
#ifndef MATCHENGINE_H
#define MATCHENGINE_H

#include "../Phase-1/Student.h"
#include "../Phase-1/Internship.h"

bool checkEligibility(Student s, Internship i);
int countMatchingSkills(Student s, Internship i);
float calculateMatchPercent(int matched, int total);

#endif
