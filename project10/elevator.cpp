#include<iostream>
#include <cstdlib>

#include "container.hpp"
#include "person.hpp"
#include "floor.hpp"
#include "car.hpp"
#include "building.hpp"

using namespace std;

int main(int argc, char** argv)
{
  if(argc!=5)
  {
    cout << "Please use the following format:" << endl;
    cout << "./elevator <iters> <floors> <cars> <traffic file>" << endl;
  }
  else
  {
    int iters = stoi(argv[1]);
    int floors = stoi(argv[2]);
    int cars = stoi(argv[3]);
    char* fileName = argv[4];
    Building b(iters,floors,cars,fileName);
    b.run();
    //figure out why person 29 is not being added
    b.summary();
  }

}
