```cpp
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

class Student{
    private:
      // Stores the basic details of the student.
      string name;
      string branch;
      int year;
      float cgpa;

      // Stores the skills provided by the student.
      vector<string>skills;

    public:
       // Declares functions to input and display student details.
       void input();

       // Returns the student's CGPA and branch.
       float getcgpa();
       string getBranch();

       // Returns the student's list of skills.
       vector<string> getSkills();

       void display();
};
```
