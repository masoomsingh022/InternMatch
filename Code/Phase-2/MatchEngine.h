```cpp
#ifndef MATCHENGINE_H
#define MATCHENGINE_H

// Includes the Student class definition from Phase 1
#include "../Phase-1/Student.h"

// Includes the Internship class definition from Phase 1
#include "../Phase-1/Internship.h"

// Checks whether a student meets the internship eligibility criteria
bool checkEligibility(Student s, Internship i);

// Counts the number of skills matching the internship requirements
int countMatchingSkills(Student s, Internship i);

// Calculates the percentage of matching skills
float calculateMatchPercent(int matched, int total);

#endif
```
