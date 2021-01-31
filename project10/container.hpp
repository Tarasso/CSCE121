#include "person.hpp"
#include <vector>

#ifndef C_H
#define C_H

using namespace std;

class Container
{
//protected:


public:
  vector<bool> buttons; // true means pressed
  vector<Person> persons;
  void Press(int f);
  bool Pressed(int f);
  void Reset(int f);
  void AddPerson(Person p);
  void RemovePerson(Person p);

};
#endif
