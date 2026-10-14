```cpp
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#pragma once 

using namespace std;

class Student{
    private:
      // Stores the student's name, branch, year, and CGPA.
      string name;
      string branch;
      int year;
      float cgpa;

      // Stores the student's skills in a list of strings.
      vector<string>skills;

    public:
       // Declares a function to take student details as input.
       void input();

       // Returns the student's CGPA and branch.
       float getcgpa();
       string getBranch();

       // Returns the list of skills entered by the student.
       vector<string> getSkills();

       // Declares a function to display student details.
       void display();
};
```
