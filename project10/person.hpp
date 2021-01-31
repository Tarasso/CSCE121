#ifndef P_H
#define P_H
#include "person.hpp"

#include <string>

using namespace std;

enum Dir { DOWN=0, UP=1 };

class Person
{
  int id;
  int start; // time when arrives at source floor
  int src; // source floor
  int dest; // destination floor
  int embarkTime; // boarding car
  int arriveTime; // arriving at destination floor

public:

  Person(int i, int Time, int s, int d);
  bool operator== (const Person& p);
  bool operator< (const Person& p);
  void setEmbarkTime(int x);
  void setArriveTime(int x);
  int getStartTime();
  int getSRC();
  int getDest();
  int getID();
  int getEmbarkTime();
  int getArriveTime();
  Dir dir(); // check implementation
  string toString();
  void print();

};
#endif
