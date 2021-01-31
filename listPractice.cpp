#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <unordered_map>

using namespace std;

int main()
{
  cout << "=== iters ===" << endl;
  list<int> L;

  //fill list 1-10
  for(int i = 0; i < 10; i++)
    L.push_back(i+1);

  //copy list
  list<int> M = L;

  //put 0's between each num
  list<int>::iterator it = L.begin();
  while( it!=L.end())
  {
    it = L.emplace(it,0);
    it++; it++;
  }

  //remove 7
  auto seven = find(L.begin(),L.end(),7);
  L.erase(seven);

  //remove 2-9
  auto a = find(L.begin(),L.end(),2);
  auto b = find(L.begin(),L.end(),9);
  L.erase(a,++b);

  //append new list to back of orginial list
  M.insert(M.end(),L.begin(),L.end());

  //print list
  for(auto num : L)
    cout << num << " ";
  cout << endl;

  //print appended list
  for(auto num : M)
    cout << num << " ";
  cout << endl;


//-------------------------

float pi = 3.14159;
float e = 2.718;
float sqrt2 = sqrt(2);
float minus1 = -1;

float vals[] = {pi,e,sqrt2,minus1};
string names[] = {"pi","e","sqrt(2)","minus1"};

for(int i = 0; i < 4; i++)
  cout << fixed << left<< setw(8) << names[i] << " = " << vals[i] << endl;

unordered_map<float,string> hash;
hash[pi] = "pi";
hash[e] = "e";
hash[sqrt2] = "sqrt(2)";
hash[minus1] = "minus1";

cout << hash[e] << " is the name of the constant " << e << endl;


}
