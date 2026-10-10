```cpp
#include <iostream>
#include <string>
#include <vector>
#include <curl/curl.h>
#include "json.hpp"
#include "Internship.h"
#include "Student.h"

using json = nlohmann::json;
using namespace std;

// Callback function to receive API response data and store it in a string
size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* output) {
    // Calculate the total size of the received data
    size_t totalSize = size * nmemb;

    // Append the received data to the output string
    output->append((char*)contents, totalSize);

    // Return the total size of the received data
    return totalSize;
}

// Function to fetch data from the given API URL
string fetchData(const string& url) {
    CURL* curl;
    CURLcode res;
    string readBuffer;

    // Initialize a CURL session
    curl = curl_easy_init();

    if (curl) {
        // Set the API URL
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        // Set the callback function to handle received data
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

        // Specify the string where the response data will be stored
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        // Allow following redirects if the URL redirects
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        // Perform the API request
        res = curl_easy_perform(curl);

        // Check whether the API request was successful
        if (res != CURLE_OK) {
            cerr << "curl error: " << curl_easy_strerror(res) << endl;
        }

        // Release the CURL session resources
        curl_easy_cleanup(curl);
    }

    // Return the API response data
    return readBuffer;
}

int main() {
    // Create a Student object
    Student s1;

    // Take student details as input
    s1.input();

    // Display the entered student details
    s1.display();

    // Store the URL of the Arbeitnow job board API
    string url = "https://www.arbeitnow.com/api/job-board-api";

    cout << "Fetching real-time data from API...\n\n";

    // Fetch job listing data from the API
    string response = fetchData(url);

    try {
        // Parse the API response string into JSON format
        json data = json::parse(response);

        // Create a vector to store Internship objects
        vector<Internship> internships;

        // Iterate through each job listing in the API response
        for (auto& job : data["data"]) {

            // Extract the job title; use "N/A" if unavailable
            string title = job.value("title", "N/A");

            // Extract the company name; use "N/A" if unavailable
            string company = job.value("company_name", "N/A");

            // Create a vector to store the job's skill tags
            vector<string> tags;

            // Check whether the job contains tags
            if (job.contains("tags")) {

                // Add each tag to the tags vector
                for (auto& tag : job["tags"]) {
                    tags.push_back(tag.get<string>());
                }
            }

            // Set the minimum CGPA requirement for the internship
            float minCgpa = 7.0;

            // Set the eligible branch for the internship
            string eligibleBranch = "CSE";

            // Create an Internship object and add it to the vector
            internships.push_back(Internship(company,title,tags,minCgpa,eligibleBranch));
        }

        // Display the total number of job listings fetched
        cout << "Total listings fetched: " << internships.size() << "\n\n";

        // Display up to the first five internship listings
        for (int i = 0; i < 5 && i < internships.size(); i++) {
            internships[i].display();
        }

    } catch (exception& e) {
        // Handle errors that occur while parsing the JSON response
        cout << "JSON parse error: " << e.what() << endl;

        // Display the first 500 characters of the response for debugging
        cout << "Raw response (first 500 chars):\n" << response.substr(0, 500) << endl;
    }

    return 0;
}
```
