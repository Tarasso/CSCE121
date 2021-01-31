#include "myVec.hpp"
#include <iostream>

using namespace std;

int main()
{
  myVec<string> words;
  words.append("Turks");
  words.append("and");
  words.append("Caicos");
  cout << words.at(0) << endl;

  myVec<float> floats;
  floats.append(3.14159);
  floats.append(2.718);
  floats.append(.5772);
  cout << floats.at(1) << endl;

  /*cout << "Test" << endl;
  myVec a;
  for(int i = 0; i < 11; i++)
  {
    a.append(i);
  }
  a.print();
  cout << "Spot 5:" << a[5] << endl;
  cout << "length:" << a.size() << endl;
  cout << a.toString() << endl;
  cout << endl << endl;
  myVec b(5);
  b.append(4);
  b.print();
  cout << endl << endl;
  myVec c = a;
  c.print();
  cout << endl << endl;
  myVec one(3);
  one.append(0);
  one.append(1);
  one.append(2);
  myVec two(3);
  two.append(3);
  two.append(4);
  two.append(5);
  myVec three = one + two;
  three.print();
  a.reverse();
  a.print();
  cout << a.find(2) << endl;
  cout << a.find(11) << endl;*/

}
