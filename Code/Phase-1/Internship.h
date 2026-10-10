```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Class to store and manage internship details
class Internship
{
    private:
        // Name of the company offering the internship
        string company;

        // Job role or internship position
        string role;

        // List of skills required for the internship
        vector<string> requiredSkills;

        // Minimum CGPA required for eligibility
        float minCgpa;

        // Branch eligible for the internship
        string eligibleBranch;

    public:
        // Constructor to initialize internship details
        Internship(string c, string r, vector<string> skills,
                   float cgpa, string branch);

        // Function to display internship information
        void display();

        // Getter function to return the minimum CGPA
        float getMinCgpa();

        // Getter function to return the eligible branch
        string getEligibleBranch();

        // Getter function to return the required skills
        vector<string> getRequiredSkills();
};
```
