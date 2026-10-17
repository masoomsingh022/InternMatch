#include<string>
using namespace std;

// Defines a base class that stores common details of a person.
// Student can inherit this class to reuse its properties (demonstrates inheritance).
class Person{
protected:
   // Stores the person's name and allows access in derived classes.
   string name;
public:
      // Declares a function to return the person's name.
      string getName();
};
