#include <iostream>
#include <stdlib.h>
#include "integerFunctions.hpp"

using namespace std;

int gcd(int a, int b)
{
  int t = 0;
  while(b != 0)
  {
   t = b;
   b = a % b;
   a = t;
  }
  return a;
}

int main()
{
  
}
