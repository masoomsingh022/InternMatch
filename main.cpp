#include <iostream>
#include <string>
#include <vector>
#include <curl/curl.h>
#include "json.hpp"
#include "Internship.h"
#include "Student.h"

using json = nlohmann::json;
using namespace std;

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

        vector<Internship> internships;

        for (auto& job : data["data"]) {
            string title = job.value("title", "N/A");
            string company = job.value("company_name", "N/A");

            vector<string> tags;
            if (job.contains("tags")) {
                for (auto& tag : job["tags"]) {
                    tags.push_back(tag.get<string>());
                }
            }
            float minCgpa = 7.0;
            string eligibleBranch = "CSE";

            internships.push_back(Internship(company,title,tags,minCgpa,eligibleBranch));
        }

        cout << "Total listings fetched: " << internships.size() << "\n\n";

        for (int i = 0; i < 5 && i < internships.size(); i++) {
            internships[i].display();
        }

    } catch (exception& e) {
        cout << "JSON parse error: " << e.what() << endl;
        cout << "Raw response (first 500 chars):\n" << response.substr(0, 500) << endl;
    }

    return 0;
}