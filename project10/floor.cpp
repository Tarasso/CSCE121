#include "person.hpp"
#include "container.hpp"
#include "floor.hpp"
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

Floor::Floor(int i)
  {
    id = i;
    buttons.push_back(false); // button 0 is down
    buttons.push_back(false); // button 1 is up
  }
bool Floor::UpPressed()
  {
    if(Pressed(1))
      return true;
    else
      return false;
  }
bool Floor::DownPressed()
  {
    if(Pressed(0))
      return true;
    else
      return false;
  }
void Floor::PressUp()
  {
    Press(1);
  }
void Floor::PressDown()
  {
    Press(0);
  }
void Floor::ClearUp()
  {
    Reset(1);
  }
void Floor::ClearDown()
  {
    Reset(0);
  }
string Floor::summary()
{
  string ret = "";
  for(int i = 0; i < persons.size(); i++)
  {
    cout << "on floor " << id << ": PERSON id " << persons[i].getID();
    cout << " src " << persons[i].getSRC() << " dest " << persons[i].getDest();
    cout << " start " << persons[i].getStartTime();
    cout << " embarked " << persons[i].getEmbarkTime() << " arrived ";
    cout << persons[i].getArriveTime() << " WAITING on FLOOR " << id << endl;

  }
  return ret;
}
string Floor::toString()
  {
    string ret = "";
    ret += "FLOOR " + to_string(id) + ", persons " + to_string(persons.size()) + ", up ";
    if(UpPressed())
      ret += "1,";
    else
      ret += "0,";
    ret += " down ";
    if(DownPressed())
      ret += "1,";
    else
      ret += "0,";
    return ret;
  }
