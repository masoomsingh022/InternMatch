
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
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
    CURL* curl;
    CURLcode res;
    string readBuffer;

    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            cerr << "curl error: " << curl_easy_strerror(res) << endl;
        }

        curl_easy_cleanup(curl);
    }

    return readBuffer;
}

int main() {
    Student s1;
    s1.input();
    s1.display();

    string url = "https://www.arbeitnow.com/api/job-board-api";

    cout << "Fetching real-time data from API...\n\n";

    string response = fetchData(url);

    try {
        json data = json::parse(response);
        LinkedList myList;

        for (auto& job : data["data"]) {
            string title = job.value("title", "N/A");
            string company = job.value("company_name", "N/A");
            vector<string> tags;

            if (job.contains("tags") && job["tags"].is_array()) {
                for (auto& tag : job["tags"]) {
                    if (tag.is_string()) {
                        tags.push_back(tag.get<string>());
                    }
                }
            }

            float minCgpa = 0.0;
            string eligibleBranch = "Not specified";

            string description = job.value("description", "");
            string searchable = title + " " + description;
            for (char &c : searchable)
                c = tolower((unsigned char)c);

            vector<string> keywords = {
                "python", "sql", "java", "c++", "machine learning",
                "artificial intelligence", "deep learning", "data science",
                "excel", "javascript", "react", "html", "css", "git",
                "linux", "docker", "aws", "tensorflow", "pytorch",
                "pandas", "numpy", "communication"
            };

            for (string keyword : keywords) {
                if (searchable.find(keyword) != string::npos)
                    tags.push_back(keyword);
            }


            Internship internship(company, title, tags, minCgpa, eligibleBranch);
            myList.insert(internship);
        }

        vector<Internship> allInternships = myList.getAllInternships();

        cout << "Total listings fetched: "
             << allInternships.size() << "\n\n";

        vector<pair<Internship, float>> results;

        for (int k = 0; k < allInternships.size(); k++) {
            if (checkEligibility(s1, allInternships[k])) {
                int matched = countMatchingSkills(s1, allInternships[k]);
                int total = s1.getSkills().size();

                if (matched > 0 && total > 0) {
                    float percent = calculateMatchPercent(matched, total);
                    results.push_back({allInternships[k], percent});
                }
            }
        }

        sort(results.begin(), results.end(),
             [](const pair<Internship, float>& a,
                const pair<Internship, float>& b) {
                 return a.second > b.second;
             });

        cout << "\n--- Top Skill Matches (Eligibility Not Verified) ---\n\n";

        if (results.empty()) {
            cout << "No skill matches found in the current listings. Try broader skills.\n";
        }

        for (int k = 0; k < 5 && k < results.size(); k++) {
            results[k].first.display();
            cout << "Your Skill Coverage: "
                 << results[k].second << "%\n\n";
        }
    }
    catch (exception& e) {
        cout << "JSON/API error: " << e.what() << endl;
        cout << "Raw response (first 500 chars):\n"
             << response.substr(0, 500) << endl;
    }

    return 0;
}
