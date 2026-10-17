#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include "../Phase-2/Person.h"
using namespace std;

class Student : public Person {
    private:
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
