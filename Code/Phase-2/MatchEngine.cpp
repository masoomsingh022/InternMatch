#include "MatchEngine.h"
#include <cctype>
#include <string>
#include <vector>
using namespace std;

// Converts text to lowercase and removes extra spaces at the ends.
string normalizeSkill(string skill) {
    for (int i = 0; i < skill.length(); i++) {
        skill[i] = tolower((unsigned char)skill[i]);
    }

    int start = 0;
    while (start < skill.length() &&
           isspace((unsigned char)skill[start])) {
        start++;
    }

    int end = skill.length();
    while (end > start &&
           isspace((unsigned char)skill[end - 1])) {
        end--;
    }

    return skill.substr(start, end - start);
}

// Checks that a skill matches a complete word or phrase,
// not just a part of another word.
bool containsSkill(string text, string skill) {
    size_t pos = text.find(skill);

    while (pos != string::npos) {
        bool leftBoundary =
            pos == 0 ||
            !isalnum((unsigned char)text[pos - 1]);

        size_t endPos = pos + skill.length();

        bool rightBoundary =
            endPos == text.length() ||
            !isalnum((unsigned char)text[endPos]);

        if (leftBoundary && rightBoundary) {
            return true;
        }

        pos = text.find(skill, pos + 1);
    }

    return false;
}

// Checks CGPA and branch eligibility.
bool checkEligibility(Student s, Internship i) {
    return s.getcgpa() >= i.getMinCgpa() &&
           normalizeSkill(s.getBranch()) ==
           normalizeSkill(i.getEligibleBranch());
}

// Counts student skills found in the internship role or tags.
int countMatchingSkills(Student s, Internship i) {
    int count = 0;

    vector<string> skills = s.getSkills();
    vector<string> tags = i.getRequiredSkills();

    string jobInfo = normalizeSkill(i.getRole());

    for (int j = 0; j < tags.size(); j++) {
        jobInfo += " " + normalizeSkill(tags[j]);
    }

    for (int x = 0; x < skills.size(); x++) {
        string skill = normalizeSkill(skills[x]);

        if (!skill.empty() && containsSkill(jobInfo, skill)) {
            count++;
        }
    }

    return count;
}

// Calculates the percentage of student skills matched.
float calculateMatchPercent(int matched, int total) {
    if (total == 0) {
        return 0;
    }

    return matched * 100.0f / total;
}
