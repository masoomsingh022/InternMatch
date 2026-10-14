
#include "MatchEngine.h"

bool checkEligibility(Student s, Internship i) {
    if (s.getcgpa() >= i.getMinCgpa() &&
        s.getBranch() == i.getEligibleBranch()) {
        return true;
    }

    return false;
}

int countMatchingSkills(Student s, Internship i) {
    int count = 0;

    for (int x = 0; x < s.getSkills().size(); x++) {
        for (int y = 0; y < i.getRequiredSkills().size(); y++) {
            if (s.getSkills()[x] == i.getRequiredSkills()[y]) {
                count++;
                break;
            }
        }
    }

    return count;
}

float calculateMatchPercent(int matched, int total) {
    if (total == 0) {
        return 0;
    }

    return (matched / (float)total) * 100;
}
