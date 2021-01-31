#include "integerFunctions.hpp"

long long fact(long long n)
{
  char buf[100000];
  if(n<=1) return 1;
  long long m = fact(n-1);
  return n*m;
}

long long fib(long long n)
{
  if(n<3) return 1;
  return fib(n-1)+fib(n-2);
}

int gcdRecur(int a, int b)
{
  if(b=0) return a;
  return gcdRecur(b, a%b);
}
