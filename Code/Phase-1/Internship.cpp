```cpp
#include "Internship.h"

// Constructor to initialize internship details
Internship::Internship(string c, string r, vector<string> skills, float cgpa, string branch){
    // Initialize company name
    company = c;

    // Initialize internship role
    role = r;

    // Store the skills required for the internship
    requiredSkills = skills;

    // Set the minimum CGPA required
    minCgpa = cgpa;

    // Set the eligible branch
    eligibleBranch = branch;
}

// Function to display all internship details
void Internship::display(){
    // Display company name
    cout << "Company: " << company << endl;

    // Display internship role
    cout << "Role: " << role << endl;

    // Display minimum CGPA requirement
    cout << "Min CGPA: " << minCgpa << endl;

    // Display eligible branch
    cout << "Eligible Branch: " << eligibleBranch << endl;

    // Display all required skills
    cout << "Required Skills: ";
    for(int i = 0; i < requiredSkills.size(); i++){
        cout << requiredSkills[i] << ", ";
    }
    cout << endl;
}

// Getter function to return the minimum CGPA
float Internship::getMinCgpa(){
    return minCgpa;
}

// Getter function to return the eligible branch
string Internship::getEligibleBranch(){
    return eligibleBranch;
}

// Getter function to return the list of required skills
vector<string> Internship::getRequiredSkills(){
    return requiredSkills;
}
```
