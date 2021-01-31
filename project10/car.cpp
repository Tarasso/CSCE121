#include "floor.hpp"
#include "person.hpp"
#include "container.hpp"
#include "car.hpp"

#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>


using namespace std;

Car::Car(int i, int f)
  {
    id = i;
    nfloors = f;
    state = MOVING;
    dir = UP;
    capacity = 0;
    floor = 0;
    for(int x = 0; x < nfloors; x++)
      buttons.push_back(false); // create nfloors buttons set to false
  }
int Car::getFloor()
  {
    return floor;
  }
string Car::toString()
  {
    //CAR 0, floor 4, load 2, state 6, dir 0, buttonsPressed: 2 3
    string ret = "";
    ret += "CAR " + to_string(id) + ", floor " + to_string(floor) + ", load ";
    ret += to_string(capacity) + ", state " + to_string(state) + ", dir ";
    ret += to_string(dir) + ", buttonsPressed: ";
    for(int i = 0; i < buttons.size(); i++)
    {
      if(Pressed(i))
      ret += to_string(i) + " ";
    }
    return ret;
  }
void Car::AddPerson(Person p)
    {
      persons.push_back(p);
      capacity++;
    }
void Car::RemovePerson(Person p)
    {
      vector<Person>:: iterator pos = persons.begin();
      for(vector<Person>::iterator iter = persons.begin(); iter!=persons.end(); iter++)
      {
        if(*iter==p)
          {
            persons.erase(iter);
            capacity--;
            break;
          }
      }
    }
int Car::getID()
{
  return id;
}
void Car::printSymbolic()
  {
    //something like CAR0[3]^
    cout << "CAR" << id << "[" << capacity << "]";
    if(state==STOPPED || state==OPEN)
      cout << "* ";
    else if(state==MOVING && dir==UP)
      cout << "^ ";
    else if(state==MOVING && dir==DOWN)
      cout << "v ";
  }
void Car::embark(Floor& floorObj, int iter)
  {
    for(int i = floorObj.persons.size()-1; i >= 0; i--)
    {
      if(floorObj.persons[i].getSRC()==floor && floorObj.persons[i].dir()==dir)
      {
        floorObj.persons[i].setEmbarkTime(iter);
        AddPerson(floorObj.persons[i]);
        Press(floorObj.persons[i].getDest());
        if(floorObj.persons[i].dir()==UP)
          floorObj.ClearUp();
        else
          floorObj.ClearDown();
        cout << "Person " << floorObj.persons[i].getID() << " embarking from floor ";
        cout << floor << " to car " << id << endl;
        floorObj.RemovePerson(floorObj.persons[i]);
      }
    }
  }
void Car::disembark(int iter, vector<Person>& allpersons)
  {
    for(int i = persons.size()-1; i >= 0; i--)
    {
      if(persons[i].getDest()==floor)
      {
        persons[i].setArriveTime(iter);
        allpersons.push_back(persons[i]);
        Reset(floor);
        cout << "Person " << persons[i].getID() << " disembarking from car ";
        cout << id << " to floor " << floor << " time " << iter << endl;
        RemovePerson(persons[i]);
      }
    }
  }
string Car::summary()
{
  string ret = "";
  for(int i = 0; i < persons.size(); i++)
  {
    cout << "in car " << id << ": PERSON id " << persons[i].getID();
    cout << " src " << persons[i].getSRC() << " dest " << persons[i].getDest();
    cout << " start " << persons[i].getStartTime();
    cout << " embarked " << persons[i].getEmbarkTime() << " arrived ";
    cout << persons[i].getArriveTime() << endl;

  }
  return ret;
}
State Car::getState()
{
  return state;
}
void Car::update(vector<Floor>& floors, int iter, vector<Person>& allpersons, vector<Car>& cars)
  {
    if(state==OPEN)
    {
      state=MOVING;
    }

    if(state==MOVING)
    {
      if(dir==UP && floor==floors.size()-1) // redirect if at top
        dir = DOWN;
        if(dir==DOWN && floor==0) // redirect if at bot
          dir = UP;

      //have any other cars stopped to open?
      bool floorInService = false;
      for(int i = 0; i < cars.size(); i++)
      {
        if(cars[i].getState()==OPEN && cars[i].getFloor()==floor)
          floorInService = true;
      }

      if( (floors[floor].UpPressed() && dir==UP && !floorInService) || //people going up
          (floors[floor].DownPressed() && dir==DOWN && !floorInService) || // people going down
          buttons[floor]==true) // people getting off
      {
        state=STOPPED;
      }

      else if(dir==UP)
      {
        floor++;
      }

      else if(dir==DOWN)
      {
        floor--;
      }

    }


    if (state==STOPPED)
    {
      disembark(iter,allpersons);
      embark(floors[floor],iter);
      state=OPEN;
    }

  }
