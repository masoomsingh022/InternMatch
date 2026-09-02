#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Internship{
    private:
      string company;
      string role;
      vector<string>requiredSkills;
      float minCgpa;
      string eligibleBranch;
      public:
        Internship(string c,string r,vector<string>skills,float cgpa,string branch){
        company=c;
        role=r;
        requiredSkills=skills;
        minCgpa=cgpa;
        eligibleBranch=branch;
    }
    void display(){
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
};