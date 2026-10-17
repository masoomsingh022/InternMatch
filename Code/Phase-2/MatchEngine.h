#ifndef MATCHENGINE_H
#define MATCHENGINE_H

#include "../Phase-1/Student.h"
#include "../Phase-1/Internship.h"

// Returns 1 = eligible, 0 = not eligible, -1 = unverified (requirements missing).
int getEligibilityStatus(Student s, Internship i);

// Compatibility helper: false only when known requirements prove ineligibility.
bool checkEligibility(Student s, Internship i);

// Counts each student skill at most once when it appears in the API tags/title.
int countMatchingSkills(Student s, Internship i);

// Percentage of entered student skills found in a listing's tags/title.
float calculateMatchPercent(int matched, int total);

// Estimates title/level fit; it is a heuristic, not employer-confirmed eligibility.
float calculateRoleFitPercent(Student s, string roleTitle);

// Combines skill coverage and title/level fit: 80% skills + 20% role fit.
float calculateOverallMatchPercent(float skillCoverage, float roleFit);

// Excludes explicit senior-level roles from the student shortlist.
bool isSeniorRole(string roleTitle);

#endif
