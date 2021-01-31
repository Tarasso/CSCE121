#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>

#include "floor.hpp"
#include "car.hpp"
#include "container.hpp"
#include "person.hpp"
#include "building.hpp"

using namespace std;

vector<string> Building::split(string s, char c)
  {
    istringstream ss(s);
    string token;
    vector<string> tokens;
    while(getline(ss,token,c))
      tokens.push_back(token);
    return tokens;
  }
void Building::AddPerson(Person p)
  {
    persons.push_back(p);
  }
void Building::AddDonePerson(Person p)
{
  donePersons.push_back(p);
}
void Building::RemovePerson(Person p)
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
void Building::readin_traffic(char* fname)
  {
    ifstream file;
    file.open(fname);
    if(!file.is_open()) cout << "Could not open file." << endl;
    string line;
    while(getline(file,line))
    {
      vector<string> vec = split(line,' ');
      if(vec[0]=="floors")
      {
        int checkFloors = stoi(vec[1]);
        int checkIter = stoi(vec[3]);
        if(nfloors!=checkFloors)
        {
          cout << "Floor count does not match" << endl;
          break;
        }
        else if(ITERS!=checkIter)
        {
          cout << "Iteration count does not match" << endl;
          break;
        }
      }
      else
      {
        Person tempPerson(stoi(vec[2]),stoi(vec[4]),stoi(vec[6]),stoi(vec[8]));
        AddPerson(tempPerson);
      }
    }

  }
Building::Building(int numiters, int numfloors, int numcars, char* fname)
  {
    ITERS = numiters;
    nfloors = numfloors;
    ncars = numcars;
    readin_traffic(fname);
    // fill vector of floors?
    for(int i = 0; i < nfloors; i++)
    {
      Floor f(i);
      floors.push_back(f);
    }
    // fill vector of cars
    for(int i = 0; i < ncars; i++)
    {
      Car c(i,nfloors);
      cars.push_back(c);
    }
  }
void Building::NewArrivals(int iter)
  {
    // check for people whose starts time has arrived
    //cout << "[";
    vector<Person> toDelete;
    for(int i = 0; i < persons.size(); i++)
    {
      //cout << persons[i].getID();
      if(persons[i].getStartTime()==iter)
      {
        floors[persons[i].getSRC()].AddPerson(persons[i]);
        //cout << "N";
        cout << "new person " << persons[i].getID() << " arriving on floor ";
        cout << persons[i].getSRC() << ", dest=" << persons[i].getDest() << endl;
        if(persons[i].dir()==UP)
          floors[persons[i].getSRC()].PressUp();
        else
          floors[persons[i].getSRC()].PressDown();
        toDelete.push_back(persons[i]);
        //RemovePerson(persons[i]);
      }
      //cout << ",";
    }
    for(int i = 0; i < toDelete.size(); i++)
    {
      RemovePerson(toDelete[i]);
    }
    //cout << "]" << endl;
  }
void Building::summary()
  {
    cout << endl;
    cout << "summary" << endl;
    for(int i = 0; i < floors.size(); i++)
    {
      string fprint = floors[i].summary();
      if (fprint != "")
        cout << fprint << endl;
    }
    for(int i = 0; i < cars.size(); i++)
    {
      string fprint = cars[i].summary();
      if (fprint != "")
        cout << fprint << endl;
    }
    for(int i = 0; i < persons.size(); i++)
    {
        cout << "PERSON id " << persons[i].getID();
        cout << " src " << persons[i].getSRC() << " dest " << persons[i].getDest();
        cout << " start " << persons[i].getStartTime();
        cout << " embarked " << persons[i].getEmbarkTime() << " arrived ";
        cout << persons[i].getArriveTime() << " ARRIVED traveltime ";
        cout << persons[i].getArriveTime()-persons[i].getStartTime() << endl;
    }

  }
void Building::find29()
{
  for(int i = 0; i < cars.size();i++)
  {
    for(int j = 0; j < cars[i].persons.size(); j++)
    {
      if(cars[i].persons[j].getID()==29)
        cout << "29 in car " << cars[i].getID() << endl;
    }
  }
  for(int i = 0; i < floors.size();i++)
  {
    for(int j = 0; j < floors[i].persons.size(); j++)
    {
      if(floors[i].persons[j].getID()==29)
        cout << "29 on floor " << i << endl;
    }
  }
  for(int i = 0; i < persons.size();i++)
  {
      if(persons[i].getID()==29)
        cout << "29 in building" << endl;
  }
}
void Building::run()
  {
    for (int iter=0 ; iter<ITERS ; iter++)
    {
      cout << endl << "iter=" << iter << endl;
      // check for Persons whose start time is now, move to source floor
      //find29();
      NewArrivals(iter);
      //find29();
      // print out contents of floors and cars
      for (int i=nfloors-1 ; i>=0 ; i--)
      {
        cout << floors[i].toString() << " ";
        for (int j=0 ; j<cars.size() ; j++)
          if (cars[j].getFloor()==i)
            cars[j].printSymbolic();
        cout << endl;
      }
      for (int i=0 ; i<cars.size() ; i++)
        cout << cars[i].toString() << endl;

      // update cars...
      for (int i=0 ; i<cars.size() ; i++)
        cars[i].update(floors,iter,persons,cars);
    }
  }
  void Building::printPeople()
  {
    for(int i = 0; i < persons.size();i++)
    {
      cout << "time " << persons[i].getStartTime() << " person " << persons[i].getID() << " arriving on floor ";
      cout << persons[i].getSRC() << ", dest=" << persons[i].getDest() << endl;
    }
  }
