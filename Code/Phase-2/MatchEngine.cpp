
#include "MatchEngine.h"
#include <cctype>
#include <string>
using namespace std;

// Checks whether a student is eligible for an internship
bool checkEligibility(Student s, Internship i) {
    // API does not provide reliable CGPA/branch requirements.
    return true;
}

int countMatchingSkills(Student s, Internship i) {
    int count = 0;
    vector<string> skills = s.getSkills();
    vector<string> tags = i.getRequiredSkills();

    for (string skill : skills) {
        for (char &c : skill) c = tolower((unsigned char)c);
        while (!skill.empty() && skill.front() == ' ')
            skill.erase(skill.begin());
        while (!skill.empty() && skill.back() == ' ')
            skill.pop_back();

        for (string tag : tags) {
            for (char &c : tag) c = tolower((unsigned char)c);
            if (!skill.empty() && tag.find(skill) != string::npos) {
                count++;
                break;
            }
        }
    }
    return count;
}


// Calculates skill match percentage
float calculateMatchPercent(int matched, int total) {

    if (total == 0) {
        return 0;
    }

    return (matched / (float)total) * 100;
}
