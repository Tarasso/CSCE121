#include "person.hpp"

#include <iostream>

using namespace std;

Person::Person(int i, int Time, int s, int d)
{
  id = i;
  start = Time; // i think this is right
  src = s;
  dest = d;
  embarkTime = -1;
  arriveTime = -1;
}
bool Person::operator== (const Person& p)
{
  if(id==p.id)
    return true;
  else
    return false;
}
bool Person::operator< (const Person& p)
{
  return start < p.start; // should be right but maybe backwards
}
void Person::setEmbarkTime(int x)
{
  embarkTime = x;
}
void Person::setArriveTime(int x)
{
  arriveTime = x;
}
int Person::getStartTime()
{
  return start;
}
int Person::getEmbarkTime()
{
  return embarkTime;
}
int Person::getArriveTime()
{
  return arriveTime;
}
int Person::getDest()
{
  return dest;
}
int Person::getSRC()
{
  return src;
}
int Person::getID()
{
  return id;
}
Dir Person::dir()
{
  Dir d;
  if(dest>src)
    d = UP;
  else
    d = DOWN;
  return d;
}
string Person::toString()
{
  string ret = "PERSON ";
  ret += "id " + to_string(id);
  ret += " src " + to_string(src);
  ret += " dest " + to_string(dest);
  ret += " start " + to_string(start);
  ret += " embarked " + to_string(embarkTime);
  ret += " arrived " + to_string(arriveTime);
  // add something about current status
  return ret;
}
void Person::print() // not sure what I need to print for a person
{
  cout << "Person: " << id;
}
