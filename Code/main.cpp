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
#include <cmath>
#include "httplib.h"

using namespace std;
using json = nlohmann::json;


// API response receive karne ke liye
size_t WriteCallback(void* contents, size_t size, size_t nmemb,
                     string* output) {

    size_t total = size * nmemb;
    output->append((char*)contents, total);

    return total;
}


// API se internship data fetch karna
string fetchData(string url) {

    CURL* curl = curl_easy_init();
    string response;

    if (curl) {

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "InternMatch/1.0");
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 20L);

        if (curl_easy_perform(curl) != CURLE_OK) {
            response.clear();
        }

        curl_easy_cleanup(curl);
    }

    return response;
}


// Text ko lowercase mein convert karna
string lowerText(string text) {

    for (int i = 0; i < (int)text.length(); i++) {
        text[i] = (char)tolower((unsigned char)text[i]);
    }

    return text;
}


// Complete word search karna
bool hasWord(const string& text, const string& word) {

    if (word.empty()) {
        return false;
    }

    size_t pos = text.find(word);

    while (pos != string::npos) {

        bool leftOk =
            (pos == 0) ||
            !isalnum((unsigned char)text[pos - 1]);

        size_t end = pos + word.size();

        bool rightOk =
            (end >= text.size()) ||
            !isalnum((unsigned char)text[end]);

        if (leftOk && rightOk) {
            return true;
        }

        pos = text.find(word, pos + 1);
    }

    return false;
}


// Similar skill names ko match karna
bool hasSkillMention(const string& text, const string& skill) {

    if (hasWord(text, skill)) {
        return true;
    }

    if (skill == "html" && hasWord(text, "html5")) {
        return true;
    }

    if (skill == "css" && hasWord(text, "css3")) {
        return true;
    }

    if (skill == "react" &&
        (hasWord(text, "reactjs") || hasWord(text, "react.js"))) {
        return true;
    }

    return false;
}


// Suitable internship aur entry-level roles identify karna
bool isSuitableRole(string title) {

    title = lowerText(title);

    // Senior-level positions reject karna
    if (hasWord(title, "senior") ||
        hasWord(title, "manager") ||
        hasWord(title, "director") ||
        hasWord(title, "principal") ||
        hasWord(title, "head") ||
        hasWord(title, "chief")) {

        return false;
    }

    // Internship aur entry-level roles
    return hasWord(title, "intern") ||
           hasWord(title, "internship") ||
           hasWord(title, "interns") ||
           hasWord(title, "junior") ||
           hasWord(title, "trainee") ||
           hasWord(title, "graduate") ||
           hasWord(title, "frontend") ||
           hasWord(title, "front-end") ||
           hasWord(title, "web developer") ||
           hasWord(title, "developer intern");
}


// Internship aur uska match score store karna
struct MatchResult {

    Internship internship;
    float score;
};


// Top 5 internship matches find karna
vector<MatchResult> getTopMatches(Student& student, string& error) {

    vector<MatchResult> results;
    error.clear();

    string response = fetchData(
        "https://www.arbeitnow.com/api/job-board-api"
    );

    if (response.empty()) {

        error = "Unable to fetch internships. Try again.";
        return results;
    }

    try {

        json data = json::parse(response);

        LinkedList internshipList;

        // API se har job ko check karna
        for (auto job : data["data"]) {

            string title = job.value("title", "N/A");
            string company = job.value("company_name", "N/A");

            // Sirf suitable roles consider karna
            if (!isSuitableRole(title)) {
                continue;
            }

            vector<string> skills;
            vector<string> apiTags;

            // API ke tags collect karna
            if (job.contains("tags") && job["tags"].is_array()) {

                for (auto tag : job["tags"]) {

                    if (tag.is_string()) {

                        apiTags.push_back(
                            lowerText(tag.get<string>())
                        );
                    }
                }
            }

            // Job title aur description combine karna
            string description = lowerText(
                title + " " + job.value("description", "")
            );

            // API tags ko skills mein store karna
            skills = apiTags;

            // Student ki entered skills check karna
            vector<string> studentSkills = student.getSkills();

            for (string skill : studentSkills) {

                skill = lowerText(skill);

                // Description aur title mein skill search karna
                if (hasSkillMention(description, skill)) {

                    skills.push_back(skill);
                }

                // API tags mein skill search karna
                for (string tag : apiTags) {

                    if (hasSkillMention(tag, skill)) {

                        skills.push_back(skill);
                        break;
                    }
                }
            }

            // Duplicate skills remove karna
            sort(skills.begin(), skills.end());

            skills.erase(
                unique(skills.begin(), skills.end()),
                skills.end()
            );

            // Internship object create karna
            Internship internship(
                company,
                title,
                skills,
                0.0f,
                "Not specified"
            );

            internshipList.insert(internship);
        }

        // Linked list se internships lena
        vector<Internship> internships =
            internshipList.getAllInternships();

        vector<string> studentSkills = student.getSkills();

        // Har internship ka matching score calculate karna
        for (int i = 0; i < (int)internships.size(); i++) {

            int matched = countMatchingSkills(
                student,
                internships[i]
            );

            // Agar koi skill match nahi hui
            if (matched == 0) {
                continue;
            }

            float score = calculateMatchPercent(
                matched,
                (int)studentSkills.size()
            );

            results.push_back({
                internships[i],
                score
            });
        }

        // Highest score wali internship pehle
        sort(
            results.begin(),
            results.end(),
            [](MatchResult a, MatchResult b) {
                return a.score > b.score;
            }
        );

        // Sirf top 5 results
        if (results.size() > 5) {

            results.erase(
                results.begin() + 5,
                results.end()
            );
        }
    }

    catch (...) {

        error = "Error processing internship data.";
        results.clear();
    }

    return results;
}


// Console mein results display karna
void printResults(vector<MatchResult>& results) {

    cout << "\n====================================\n";
    cout << "       TOP 5 INTERNSHIP MATCHES\n";
    cout << "====================================\n";

    if (results.empty()) {

        cout << "No matching internships found.\n";
    }

    for (int i = 0; i < (int)results.size(); i++) {

        cout << "\nRank #" << i + 1 << "\n";

        results[i].internship.display();

        cout << "Match Score: "
             << results[i].score << "%\n";

        cout << "------------------------------------\n";
    }
}


// Menu choice read karna
int readChoice() {

    string line;

    if (!getline(cin, line)) {
        return 4;
    }

    try {

        size_t pos;
        int choice = stoi(line, &pos);

        if (pos != line.length()) {
            return 0;
        }

        return choice;
    }

    catch (...) {
        return 0;
    }
}


// GUI server start karna
void startServer() {

    httplib::Server svr;

    // Web folder se HTML, CSS aur JS serve karna
    if (!svr.set_mount_point("/", "./web")) {

        cout << "Web folder not found. Please run the program from the project root directory.\n";
        return;
    }

    // Browser se student profile receive karna
    svr.Post("/match", [](const httplib::Request& req,
                          httplib::Response& res) {

        try {

            json in = json::parse(req.body);

            Student student;

            student.setProfile(
                in.value("name", ""),
                in.value("branch", ""),
                in.value("year", 0),
                in.value("cgpa", 0.0f),
                in.value("skills", "")
            );

            if (student.getSkills().empty()) {

                res.status = 400;

                res.set_content(
                    json{
                        {"error", "Please enter at least one skill."}
                    }.dump(),
                    "application/json"
                );

                return;
            }

            string error;

            vector<MatchResult> top =
                getTopMatches(student, error);

            if (!error.empty()) {

                res.status = 502;

                res.set_content(
                    json{{"error", error}}.dump(),
                    "application/json"
                );

                return;
            }

            // Results ko JSON format mein convert karna
            json out = json::array();

            for (auto& r : top) {

                out.push_back({

                    {"company", r.internship.getCompany()},

                    {"title", r.internship.getRole()},

                    {"skills", r.internship.getRequiredSkills()},

                    {"score", round(
                        (double)r.score * 10.0
                    ) / 10.0}

                });
            }

            res.set_content(
                out.dump(),
                "application/json"
            );
        }

        catch (...) {

            res.status = 400;

            res.set_content(
                json{{"error", "Invalid request."}}.dump(),
                "application/json"
            );
        }
    });

    cout << "\nGUI running at http://localhost:8080\n";
    cout <<"Open this link in your browser. Press Ctrl+C to stop the server.\n";

    svr.listen("127.0.0.1", 8080);
}


// Main function
int main() {

    curl_global_init(CURL_GLOBAL_DEFAULT);

    Student student;

    bool profileEntered = false;

    while (true) {

        cout << "\n========== INTERNMATCH ==========\n";

        cout << "1. Enter Student Profile\n";
        cout << "2. Find Internship Matches\n";
        cout << "3. Open GUI\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";

        int choice = readChoice();

        // Student profile enter karna
        if (choice == 1) {

            student = Student();

            student.input();

            profileEntered = true;

            cout << "\nProfile saved successfully!\n";
        }

        // Console matches find karna
        else if (choice == 2) {

            if (profileEntered == false) {

                cout << "\nPlease enter your profile first.\n";
                continue;
            }

            cout << "\nFetching internships...\n";

            string error;

            vector<MatchResult> results =
                getTopMatches(student, error);

            if (!error.empty()) {

                cout << error << endl;
            }

            else {

                printResults(results);
            }
        }

        // GUI open karna
        else if (choice == 3) {

            startServer();
        }

        // Exit
        else if (choice == 4) {

            cout << "\nThank you for using InternMatch!\n";

            break;
        }

        else {

            cout << "\nInvalid choice. Please try again.\n";
        }
    }

    curl_global_cleanup();

    return 0;
}
