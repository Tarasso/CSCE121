#include "container.hpp"
#include "person.hpp"

#include <vector>
#include <iostream>

using namespace std;

void Container::Press(int f)
  {
    buttons[f] = true;
  }
bool Container::Pressed(int f)
  {
    if(buttons[f]==true)
      return true;
    else
      return false;
  }
void Container::Reset(int f)
  {
    buttons[f] = false;
  }
void Container::AddPerson(Person p)
  {
    persons.push_back(p);
  }
void Container::RemovePerson(Person p)
  {
    vector<Person>:: iterator pos = persons.begin();
    for(vector<Person>::iterator iter = persons.begin(); iter!=persons.end(); iter++)
    {
      if(*iter==p)
        {
          persons.erase(iter);
          break;
        }
    }
  }
