#include "Internship.h"

Internship::Internship(string c, string r, vector<string> skills, float cgpa, string branch){
    company = c;
    role = r;
    requiredSkills = skills;
    minCgpa = cgpa;
    eligibleBranch = branch;
}

void Internship::display(){
    cout << "Company: " << company << endl;
    cout << "Role: " << role << endl;
    cout << "Min CGPA: " << minCgpa << endl;
    cout << "Eligible Branch: " << eligibleBranch << endl;
    cout << "Required Skills: ";
    for(int i = 0; i < requiredSkills.size(); i++){
        cout << requiredSkills[i] << ", ";
    }
    cout << endl;
}

float Internship::getMinCgpa(){
    return minCgpa;
}

string Internship::getEligibleBranch(){
    return eligibleBranch;
}

vector<string> Internship::getRequiredSkills(){
    return requiredSkills;
}