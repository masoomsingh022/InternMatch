#include<string>
using namespace std;

// Base class representing a generic person.
// Intended to be inherited by Student (demonstrates OOP inheritance).
class Person{
protected:
   string name;
public:
      string getName();
};
