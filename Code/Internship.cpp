#include "Internship.h"

Internship::Internship(string c, string r, vector<string> skills, float cgpa, string branch) {
    company = c;
    role = r;
    requiredSkills = skills;
    minCgpa = cgpa;
    eligibleBranch = branch;
}

void Internship::display() {
    cout << "Company: " << company << endl;
    cout << "Role: " << role << endl;

    if (minCgpa > 0)
        cout << "Min CGPA: " << minCgpa << endl;
    else
        cout << "Min CGPA: Not provided by API" << endl;

    if (eligibleBranch.empty() || eligibleBranch == "Not specified")
        cout << "Eligible Branch: Not provided by API" << endl;
    else
        cout << "Eligible Branch: " << eligibleBranch << endl;

    cout << "API Tags / Keywords: ";
    for (int i = 0; i < requiredSkills.size(); i++)
        cout << requiredSkills[i] << ", ";
    cout << endl;
}

float Internship::getMinCgpa() {
    return minCgpa;
}

string Internship::getEligibleBranch() {
    return eligibleBranch;
}

vector<string> Internship::getRequiredSkills() {
    return requiredSkills;
}

// New getter to allow the ranking code to access the role title.
string Internship::getRole() {
    return role;
}
