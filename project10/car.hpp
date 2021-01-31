#include "floor.hpp"
#include "person.hpp"
#include "container.hpp"

#include <vector>

using namespace std;

#ifndef CAR_H
#define CAR_H

enum State {STOPPED, MOVING, OPEN};

class Car : public Container
{
  int id;
  int floor;
  int capacity;
  State state;
  Dir dir; // direction car is moving **** do something with
  int nfloors;
  //also has vector of buttons
  //also has vector of persons

public:

  Car(int i, int f);
  int getFloor();
  string toString();
  void printSymbolic();
  int getID();
  void update(vector<Floor>& floors, int iter, vector<Person>& allpersons, vector<Car>& cars);
  void embark(Floor& floorObj, int iter);
  void disembark(int iter, vector<Person>& allpersons);
  void AddPerson(Person p);
  void RemovePerson(Person p);
  State getState();
  string summary();
};
#endif
