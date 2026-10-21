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

// Eligibility has three possible outcomes:
// 1 = Eligible (all supplied requirements passed)
// 0 = Not eligible (a supplied requirement failed)
// -1 = Unverified (CGPA or branch requirements are missing)
int getEligibilityStatus(Student s, Internship i) {
    bool checkedAtLeastOneRequirement = false;

    float requiredCgpa = i.getMinCgpa();
    if (requiredCgpa > 0) {
        checkedAtLeastOneRequirement = true;
        if (s.getcgpa() < requiredCgpa)
            return 0;
    }

    string requiredBranch = normalizeText(i.getEligibleBranch());
    bool branchMissing = requiredBranch.empty() ||
        requiredBranch == "not specified" ||
        requiredBranch == "not provided" ||
        requiredBranch == "not provided by api" ||
        requiredBranch == "unknown" || requiredBranch == "n/a";

    if (!branchMissing) {
        checkedAtLeastOneRequirement = true;
        if (requiredBranch != "all" && requiredBranch != "any" &&
            requiredBranch != "all branches" && requiredBranch != "any branch") {
            string studentBranch = normalizeText(s.getBranch());
            bool branchMatches = (studentBranch == requiredBranch);

            // Also support simple comma/slash/semicolon-separated branch lists.
            for (char &c : requiredBranch) {
                if (c == ',' || c == '/' || c == ';' || c == '|')
                    c = ' ';
            }
            stringstream branchList(requiredBranch);
            string option;
            while (!branchMatches && branchList >> option) {
                if (studentBranch == option)
                    branchMatches = true;
            }
            if (!branchMatches)
                return 0;
        }
    }

    //A pass on just one criterion is not a complete eligibility verification.
    if (!checkedAtLeastOneRequirement || requiredCgpa <= 0 || branchMissing)
        return -1;
    return 1;
}

// Keep the existing bool function for compatibility with other code.
// Unknown requirements are not treated as a confirmed rejection.
bool checkEligibility(Student s, Internship i) {
    return getEligibilityStatus(s, i) != 0;
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
