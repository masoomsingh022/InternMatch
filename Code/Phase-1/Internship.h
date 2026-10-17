#pragma once

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Class to store internship details
class Internship
{
private:
    string company;
    string role;
    vector<string> requiredSkills;
    float minCgpa;
    string eligibleBranch;

public:
    Internship(string c, string r, vector<string> skills,
               float cgpa, string branch);

    void display();

    float getMinCgpa();
    string getEligibleBranch();
    vector<string> getRequiredSkills();
    string getRole();
};
