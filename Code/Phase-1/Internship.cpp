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
    // Company ka naam print karo
    cout << "Company: " << company << endl;

    // Role print karo
    cout << "Role: " << role << endl;

    // Minimum CGPA print karo
    cout << "Min CGPA: " << minCgpa << endl;

    // Eligible branch print karo
    cout << "Eligible Branch: " << eligibleBranch << endl;

    // Saari required skills print karo
    cout << "Required Skills: ";
    for (int i = 0; i < requiredSkills.size(); i++) {
        cout << requiredSkills[i] << ", ";
    }
    cout << endl;
}

// Minimum CGPA return karta hai
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
