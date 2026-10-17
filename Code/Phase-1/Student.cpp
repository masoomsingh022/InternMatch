#include "Student.h"
#include <sstream>
#include <iostream>
using namespace std;

void Student::input(){
    cout << "enter name\n";
    getline(cin, name);
    cout << "enter branch\n";
    getline(cin, branch);
    cout << "enter year\n";
    cin >> year;
    cout << "enter cgpa\n";
    cin >> cgpa;
    cin.ignore();
    cout << "enter skills in comma separated form\n";
    string skillInput;
    getline(cin,skillInput);
    stringstream ss(skillInput);
    string oneSkill;
    while(getline(ss,oneSkill,',')){
        skills.push_back(oneSkill);
    }
}

float Student::getcgpa(){
    return cgpa;
}

string Student::getBranch(){
    return branch;
}

vector<string> Student::getSkills(){
    return skills;
}

void Student::display(){
    int i;
    cout<<"Name:"<<name<<endl;
    cout<<"Branch:"<<branch<<endl;
    cout<<"Year:"<<year<<endl;
    cout<<"Cgpa:"<<cgpa<<endl;
    cout<<"Skills are:";
    for(i=0;i<skills.size();i++){
        cout<<skills[i]<<",";
    }
    cout<<endl;
}
