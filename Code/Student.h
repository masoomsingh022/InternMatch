#pragma once
#include "Person.h"
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

class Student : public Person {
    private:
      string branch;
      int year;
      float cgpa;
      vector<string> skills;

    public:
    void input();
    void setProfile(string n, string b, int y, float c, string skillsCsv);
    float getcgpa();
    string getBranch();
    vector<string> getSkills();
    void display();
};
