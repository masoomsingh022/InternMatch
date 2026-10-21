#include "MatchEngine.h"
#include <cctype>
#include <string>
#include <vector>

using namespace std;

string normalizeText(string text) {
    for (char &c : text) {
        c = (char)tolower((unsigned char)c);
    }
    return text;
}

int getEligibilityStatus(Student s, Internship i) {
    float requiredCgpa = i.getMinCgpa();

    string requiredBranch = normalizeText(i.getEligibleBranch());
    string studentBranch = normalizeText(s.getBranch());

    bool cgpaAvailable = requiredCgpa > 0;

    bool branchAvailable =
        !requiredBranch.empty() &&
        requiredBranch != "not specified" &&
        requiredBranch != "not provided by api";

    if (!cgpaAvailable && !branchAvailable) {
        return -1;
    }

    if (cgpaAvailable && s.getcgpa() < requiredCgpa) {
        return 0;
    }

    if (branchAvailable && studentBranch != requiredBranch) {
        return 0;
    }

    return 1;
}

bool checkEligibility(Student s, Internship i) {
    return getEligibilityStatus(s, i) != 0;
}

int countMatchingSkills(Student s, Internship i) {
    int count = 0;

    vector<string> studentSkills = s.getSkills();
    vector<string> requiredSkills = i.getRequiredSkills();

    for (int x = 0; x < (int)studentSkills.size(); x++) {
        string studentSkill = normalizeText(studentSkills[x]);

        for (int y = 0; y < (int)requiredSkills.size(); y++) {
            string requiredSkill = normalizeText(requiredSkills[y]);

            if (studentSkill == requiredSkill) {
                count++;
                break;
            }
        }
    }

    return count;
}

float calculateMatchPercent(int matched, int total) {
    if (total <= 0) {
        return 0.0f;
    }

    return (matched / (float)total) * 100.0f;
}

float calculateRoleFitPercent(Student s, string roleTitle) {
    string title = normalizeText(roleTitle);

    if (title.find("phd") != string::npos ||
        title.find("doctoral") != string::npos ||
        title.find("doctorate") != string::npos) {
        return 20.0f;
    }

    vector<string> skills = s.getSkills();

    vector<string> technicalRoles = {
        "software", "developer", "programmer", "data",
        "machine learning", "artificial intelligence",
        "automation", "engineering", "computer",
        "database", "technology", "cyber", "cloud"
    };

    vector<string> technicalSkills = {
        "python", "machine learning", "c++", "sql",
        "dsa", "java", "javascript", "data science",
        "deep learning", "artificial intelligence"
    };

    bool hasTechnicalSkill = false;

    for (string skill : skills) {
        skill = normalizeText(skill);

        for (const string& technical : technicalSkills) {
            if (skill == technical) {
                hasTechnicalSkill = true;
                break;
            }
        }

        if (hasTechnicalSkill) {
            break;
        }
    }

    for (const string& role : technicalRoles) {
        if (title.find(role) != string::npos &&
            hasTechnicalSkill) {
            return 80.0f;
        }
    }

    if (title.find("intern") != string::npos) {
        return 50.0f;
    }

    return 30.0f;
}

float calculateOverallMatchPercent(float skillCoverage, float roleFit) {
    return 0.80f * skillCoverage + 0.20f * roleFit;
}