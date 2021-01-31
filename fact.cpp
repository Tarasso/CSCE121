#include <iostream>
#include <stdlib.h>
#include "integerFunctions.hpp"

using namespace std;

long long factIter(long long n)
{
  long long res=1;
  while(n > 1) res*= n--;
  return res;
}

int main(int charc, char** charv)
{
 cout << fact(atoi(charv[1])) << endl;
 cout << factIter(atoi(charv[1])) << endl;
}
