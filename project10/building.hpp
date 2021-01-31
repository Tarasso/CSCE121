#include <cstdlib>
#include <vector>

#include "floor.hpp"
#include "car.hpp"
#include "container.hpp"
#include "person.hpp"


#ifndef B_H
#define B_H

using namespace std;

class Building
{
  int ncars;
  int nfloors;
  int ITERS;

  vector<Floor> floors;
  vector<Car> cars;
  vector<Person> persons;
  vector<Person> donePersons;

public:

  vector<string> split(string s, char c);
  void AddPerson(Person p);
  void AddDonePerson(Person p);
  void RemovePerson(Person p);
  void readin_traffic(char* fname);
  Building(int numiters, int numfloors, int numcars, char* fname);
  void NewArrivals(int iter);
  void summary();
  void find29();
  void run();
  void printPeople();
};
#endif
