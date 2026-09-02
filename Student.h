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
       void input(){
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
        void display(){
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
};