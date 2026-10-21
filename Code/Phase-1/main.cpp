
#include <iostream>
#include <string>
#include <vector>
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

size_t WriteCallback(void* contents, size_t size, size_t nmemb,
                     string* output) {
    size_t total = size * nmemb;
    output->append((char*)contents, total);
    return total;
}

string fetchData(string url) {
    CURL* curl = curl_easy_init();
    string response;

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "InternMatch/1.0");

        if (curl_easy_perform(curl) != CURLE_OK) {
            response.clear();
        }

        curl_easy_cleanup(curl);
    }

    return response;
}

string lowerText(string text) {
    for (int i = 0; i < (int)text.length(); i++) {
        text[i] = tolower((unsigned char)text[i]);
    }
    return text;
}

bool isSuitableRole(string title) {
    title = lowerText(title);

    if (title.find("senior") != string::npos ||
        title.find("manager") != string::npos ||
        title.find("director") != string::npos ||
        title.find("principal") != string::npos) {
        return false;
    }

    return title.find("intern") != string::npos ||
           title.find("junior") != string::npos ||
           title.find("trainee") != string::npos ||
           title.find("graduate") != string::npos;
}

struct MatchResult {
    Internship internship;
    float score;
};

int main() {
    Student student;
    student.input();

    cout << "\nFetching internships...\n";

    string response = fetchData(
        "https://www.arbeitnow.com/api/job-board-api"
    );

    if (response.empty()) {
        cout << "Unable to fetch internships. Try again.\n";
        return 1;
    }

    try {
        json data = json::parse(response);
        LinkedList internshipList;

        for (auto job : data["data"]) {
            string title = job.value("title", "N/A");
            string company = job.value("company_name", "N/A");

            if (!isSuitableRole(title)) {
                continue;
            }

            vector<string> skills;

            if (job.contains("tags") && job["tags"].is_array()) {
                for (auto tag : job["tags"]) {
                    if (tag.is_string()) {
                        skills.push_back(
                            lowerText(tag.get<string>())
                        );
                    }
                }
            }

            string description = lowerText(
                title + " " + job.value("description", "")
            );

            vector<string> keywords = {
                "python", "sql", "java", "c++", "git",
                "machine learning", "data science",
                "software", "javascript", "deep learning"
            };

            for (string word : keywords) {
                if (description.find(word) != string::npos) {
                    skills.push_back(word);
                }
            }

            sort(skills.begin(), skills.end());
            skills.erase(
                unique(skills.begin(), skills.end()),
                skills.end()
            );

            Internship internship(
                company, title, skills, 0.0f, "Not specified"
            );

            internshipList.insert(internship);
        }

        vector<Internship> internships =
            internshipList.getAllInternships();

        vector<MatchResult> results;
        vector<string> studentSkills = student.getSkills();

        for (int i = 0; i < (int)internships.size(); i++) {
            int matched = countMatchingSkills(
                student, internships[i]
            );

            if (matched == 0) {
                continue;
            }

            float score = calculateMatchPercent(
                matched, (int)studentSkills.size()
            );

            results.push_back({internships[i], score});
        }

        sort(results.begin(), results.end(),
             [](MatchResult a, MatchResult b) {
                 return a.score > b.score;
             });

        cout << "\n====================================\n";
        cout << "       TOP 5 INTERNSHIP MATCHES\n";
        cout << "====================================\n";

        int limit = min(5, (int)results.size());

        if (limit == 0) {
            cout << "No matching internships found.\n";
        }

        for (int i = 0; i < limit; i++) {
            cout << "\nRank #" << i + 1 << "\n";
            results[i].internship.display();
            cout << "Match Score: "
                 << results[i].score << "%\n";
            cout << "------------------------------------\n";
        }
    }
    catch (...) {
        cout << "Error processing internship data.\n";
        return 1;
    }

    return 0;
}
