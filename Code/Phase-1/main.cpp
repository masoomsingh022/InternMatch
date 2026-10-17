#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <cctype>
#include <curl/curl.h>
#include "json.hpp"
#include "Internship.h"
#include "Student.h"
#include "LinkedList.h"
#include "MatchEngine.h"

using namespace std;
using json = nlohmann::json;

size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* output) {
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

string fetchData(const string& url) {
    CURL* curl = curl_easy_init();
    CURLcode res;
    string readBuffer;

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
            cerr << "curl error: " << curl_easy_strerror(res) << endl;
        curl_easy_cleanup(curl);
    }
    return readBuffer;
}

static string lowerText(string value) {
    for (char &c : value)
        c = (char)tolower((unsigned char)c);
    return value;
}

static bool hasWholeWord(const string& text, const string& word) {
    size_t pos = text.find(word);
    while (pos != string::npos) {
        bool leftBoundary = (pos == 0) || !isalnum((unsigned char)text[pos - 1]);
        size_t after = pos + word.size();
        bool rightBoundary = (after == text.size()) || !isalnum((unsigned char)text[after]);
        if (leftBoundary && rightBoundary)
            return true;
        pos = text.find(word, pos + 1);
    }
    return false;
}

// Exclude clearly senior positions from a student internship shortlist.
static bool isSeniorRole(string title) {
    title = lowerText(title);
    // Keep explicitly named internships even if the title contains one of these words.
    if (hasWholeWord(title, "intern") || hasWholeWord(title, "internship"))
        return false;

    const vector<string> seniorWords = {
        "senior", "staff", "principal", "manager", "director",
        "head", "chief", "lead", "vp"
    };
    for (string word : seniorWords) {
        if (hasWholeWord(title, word))
            return true;
    }
    if (title.find("vice president") != string::npos)
        return true;
    return false;
}

// Simple explainable title-fit heuristic: internship > early-career > general role.
static float calculateTitleFit(string title) {
    title = lowerText(title);
    if (hasWholeWord(title, "intern") || hasWholeWord(title, "internship"))
        return 100.0f;

    const vector<string> earlyCareerWords = {
        "junior", "trainee", "graduate", "apprentice", "working student", "entry-level", "entry level"
    };
    for (string word : earlyCareerWords) {
        if (title.find(word) != string::npos)
            return 70.0f;
    }
    return 40.0f;
}

struct MatchResult {
    Internship internship;
    float skillCoverage;
    float titleFit;
    float finalScore;
};

int main() {
    Student student;
    student.input();
    student.display();

    string url = "https://www.arbeitnow.com/api/job-board-api";
    cout << "Fetching real-time data from API...\n\n";
    string response = fetchData(url);

    try {
        json data = json::parse(response);
        LinkedList internshipList;

        for (auto& job : data["data"]) {
            string title = job.value("title", "N/A");
            string company = job.value("company_name", "N/A");
            vector<string> tags;

            if (job.contains("tags") && job["tags"].is_array()) {
                for (auto& tag : job["tags"]) {
                    if (tag.is_string())
                        tags.push_back(tag.get<string>());
                }
            }

            // The API does not provide reliable CGPA/branch criteria.
            // Keep them marked as unspecified instead of making up values.
            float minCgpa = 0.0f;
            string eligibleBranch = "Not specified";

            string description = job.value("description", "");
            string searchable = lowerText(title + " " + description);
            const vector<string> keywords = {
                "python", "sql", "java", "c++", "machine learning",
                "artificial intelligence", "deep learning", "data science",
                "excel", "javascript", "react", "html", "css", "git",
                "linux", "docker", "aws", "tensorflow", "pytorch",
                "pandas", "numpy", "communication"
            };
            for (const string& keyword : keywords) {
                if (searchable.find(keyword) != string::npos)
                    tags.push_back(keyword);
            }

            Internship internship(company, title, tags, minCgpa, eligibleBranch);
            internshipList.insert(internship);
        }

        vector<Internship> allInternships = internshipList.getAllInternships();
        cout << "Total listings fetched: " << allInternships.size() << "\n\n";

        vector<MatchResult> results;
        for (int k = 0; k < (int)allInternships.size(); k++) {
            string role = allInternships[k].getRole();
            if (isSeniorRole(role))
                continue;

            if (checkEligibility(student, allInternships[k])) {
                int matched = countMatchingSkills(student, allInternships[k]);
                int total = (int)student.getSkills().size();
                if (matched > 0 && total > 0) {
                    float skillCoverage = calculateMatchPercent(matched, total);
                    float titleFit = calculateTitleFit(role);
                    // Simple weighted ranking: 80% skills + 20% title fit.
                    float finalScore = 0.80f * skillCoverage + 0.20f * titleFit;
                    results.push_back({allInternships[k], skillCoverage, titleFit, finalScore});
                }
            }
        }

        stable_sort(results.begin(), results.end(),
            [](const MatchResult& a, const MatchResult& b) {
                return a.finalScore > b.finalScore;
            });

        cout << "--- Top Skill Matches (Eligibility Not Verified) ---\n\n";
        if (results.empty()) {
            cout << "No skill matches found in the current listings. Try broader skills.\n";
        }

        for (int k = 0; k < 5 && k < (int)results.size(); k++) {
            results[k].internship.display();
            cout << "Your Skill Coverage: " << results[k].skillCoverage << "%\n";
            cout << "Role Fit Estimate: " << results[k].titleFit << "%\n";
            cout << "Estimated Match Score: " << results[k].finalScore << "%\n\n";
        }
    }
    catch (exception& e) {
        cout << "JSON/API error: " << e.what() << endl;
        cout << "Raw response (first 500 chars):\n" << response.substr(0, 500) << endl;
    }
    return 0;
}
