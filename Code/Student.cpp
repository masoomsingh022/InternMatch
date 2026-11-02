#include "Student.h"
#include <sstream>
#include <iostream>
using namespace std;


void Student::input(){
    skills.clear();

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
    getline(cin, skillInput);

    stringstream ss(skillInput);
    string oneSkill;

    while(getline(ss, oneSkill, ',')){
        size_t start = oneSkill.find_first_not_of(" \t");
        if(start != string::npos){
            size_t end = oneSkill.find_last_not_of(" \t");
            oneSkill = oneSkill.substr(start, end - start + 1);

            skills.push_back(oneSkill);
        }
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
void Student::setProfile(string n, string b, int y, float c, string skillsCsv)
{
    name = n;
    branch = b;
    year = y;
    cgpa = c;

    // Remove old skills
    skills.clear();

    // Convert comma-separated skills into individual skills
    stringstream ss(skillsCsv);

    string oneSkill;

    while (getline(ss, oneSkill, ','))
    {
        size_t start = oneSkill.find_first_not_of(" \t\r\n");

        if (start == string::npos)
        {
            continue;
        }

        size_t end = oneSkill.find_last_not_of(" \t\r\n");

        oneSkill = oneSkill.substr(start, end - start + 1);

        skills.push_back(oneSkill);
    }
}
