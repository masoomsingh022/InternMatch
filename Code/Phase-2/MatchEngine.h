#ifndef MATCHENGINE_H
#define MATCHENGINE_H

#include "../Phase-1/Student.h"
#include "../Phase-1/Internship.h"

// Returns 1 if eligible, 0 if not eligible, and -1 if requirements are missing.
int getEligibilityStatus(Student s, Internship i);

// Returns false only if the available requirements confirm ineligibility.
bool checkEligibility(Student s, Internship i);

// Counts student skills that match the API tags or internship title.
int countMatchingSkills(Student s, Internship i);

// Calculates the percentage of student skills found in the listing.
float calculateMatchPercent(int matched, int total);

// Estimates how well the role title matches the student's level.
float calculateRoleFitPercent(Student s, string roleTitle);

// Calculates the final match score using 80% skills and 20% role fit.
float calculateOverallMatchPercent(float skillCoverage, float roleFit);

// Checks whether the role is explicitly intended for senior-level candidates.
bool isSeniorRole(string roleTitle);

#endif
