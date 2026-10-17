#include "MatchEngine.h"
#include <cctype>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// Lowercase text and remove spaces from both ends.
static string normalizeText(string value) {
    while (!value.empty() && isspace((unsigned char)value.front()))
        value.erase(value.begin());
    while (!value.empty() && isspace((unsigned char)value.back()))
        value.pop_back();
    for (char &c : value)
        c = (char)tolower((unsigned char)c);
    return value;
}

// Checks actual requirements only when the API supplies them.
// Missing values remain unverified; we do not invent requirements.
bool checkEligibility(Student s, Internship i) {
    float requiredCgpa = i.getMinCgpa();
    if (requiredCgpa > 0 && s.getcgpa() < requiredCgpa)
        return false;

    string requiredBranch = normalizeText(i.getEligibleBranch());
    if (requiredBranch.empty() || requiredBranch == "not specified" ||
        requiredBranch == "not provided" || requiredBranch == "unknown")
        return true;

    if (requiredBranch == "all" || requiredBranch == "any" ||
        requiredBranch == "all branches" || requiredBranch == "any branch")
        return true;

    string studentBranch = normalizeText(s.getBranch());
    if (studentBranch == requiredBranch)
        return true;

    // Supports branch lists such as "CSE, ECE / IT".
    for (char &c : requiredBranch) {
        if (c == ',' || c == '/' || c == ';' || c == '|')
            c = ' ';
    }
    stringstream branchList(requiredBranch);
    string option;
    while (branchList >> option) {
        if (studentBranch == option)
            return true;
    }
    return false;
}

// Exact case-insensitive matching prevents "c" matching "communication"
// and "java" matching "javascript".
int countMatchingSkills(Student s, Internship i) {
    int count = 0;
    vector<string> skills = s.getSkills();
    vector<string> tags = i.getRequiredSkills();

    for (string skill : skills) {
        skill = normalizeText(skill);
        if (skill.empty())
            continue;

        for (string tag : tags) {
            tag = normalizeText(tag);
            if (skill == tag) {
                count++;
                break; // Count each student skill once.
            }
        }
    }
    return count;
}

float calculateMatchPercent(int matched, int total) {
    if (total <= 0)
        return 0.0f;
    return (matched * 100.0f) / total;
}
