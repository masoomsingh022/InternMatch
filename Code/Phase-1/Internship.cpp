#include "Internship.h"

// Constructor: internship ki details set karta hai
Internship::Internship(string c, string r, vector<string> skills, float cgpa, string branch) {
    // Company ka naam set karo
    company = c;

    // Internship ka role set karo
    role = r;

    // Internship ke liye zaroori skills save karo
    requiredSkills = skills;

    // Minimum CGPA set karo
    minCgpa = cgpa;

    // Eligible branch set karo
    eligibleBranch = branch;
}

// Internship ki saari details display karta hai
void Internship::display() {
    cout << "Company: " << company << endl;
    cout << "Role: " << role << endl;

    if (minCgpa > 0)
        cout << "Min CGPA: " << minCgpa << endl;
    else
        cout << "Min CGPA: Not provided by API" << endl;

    if (eligibleBranch.empty() ||
        eligibleBranch == "Not specified")
        cout << "Eligible Branch: Not provided by API" << endl;
    else
        cout << "Eligible Branch: " << eligibleBranch << endl;

    cout << "API Tags: ";
    for (int i = 0; i < requiredSkills.size(); i++)
        cout << requiredSkills[i] << ", ";
    cout << endl;
}

float Internship::getMinCgpa() {
    return minCgpa;
}

// Eligible branch return karta hai
string Internship::getEligibleBranch() {
    return eligibleBranch;
}

// Required skills ki list return karta hai
vector<string> Internship::getRequiredSkills() {
    return requiredSkills;
}
