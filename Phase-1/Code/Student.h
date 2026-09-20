#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
class Student{
    private:
      string name;
      string branch;
      int year;
      float cgpa;
      vector<string>skills;
    public:
       void input();
       float getcgpa();
       string getBranch();
       vector<string> getSkills();
       void display();

};