```cpp
#include "MatchEngine.h"  // Includes the declarations required for the matching functions

// Checks whether a student is eligible for an internship
bool checkEligibility(Student s, Internship i) {

    // Checks whether the student's CGPA meets the minimum requirement
    // Also checks whether the student's branch matches the eligible branch
    if (s.getcgpa() >= i.getMinCgpa() &&
        s.getBranch() == i.getEligibleBranch()) {

        return true;  // Student satisfies both eligibility conditions
    }

    return false;  // Student does not satisfy the eligibility conditions
}


// Counts the number of skills that match the internship requirements
int countMatchingSkills(Student s, Internship i) {

    int count = 0;  // Initially, no matching skills have been found

    // Iterates through all the skills possessed by the student
    for (int x = 0; x < s.getSkills().size(); x++) {

        // Compares the current student skill with each required internship skill
        for (int y = 0; y < i.getRequiredSkills().size(); y++) {

            // Checks whether the student skill matches a required skill
            if (s.getSkills()[x] == i.getRequiredSkills()[y]) {

                count++;  // Increases the count when a matching skill is found

                break;  // Stops checking once a match is found for this skill
            }
        }
    }

    return count;  // Returns the total number of matching skills
}


// Calculates the percentage of required skills matched by the student
float calculateMatchPercent(int matched, int total) {

    // Prevents division by zero when there are no required skills
    if (total == 0) {
        return 0;
    }

    // Calculates the match percentage using matched and total skills
    // Converts total to float to perform floating-point division
    return (matched / (float)total) * 100;
}
```
