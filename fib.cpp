#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include "integerFunctions.hpp"

using namespace std;

long long fib(long long n,vector<long long>& keys)
{
  if (keys[n-1] != -1) return keys[n-1];
  if(n<3) return 1;
  else keys[n-1] = fib(n-1,keys)+fib(n-2,keys);
  return keys[n-1];
}

vector<long long> fibDP(long long n)
{
  vector<long long> keys(n,-1);
  fib(n,keys);
  return keys;

}

int main(int argc, char** argv)
{
  long long upper = atoi(argv[1]);
  /*vector<long long> keys = fibDP(upper);
  for(long long i = 0; i < upper; i++)
  {
    cout << "fib("<<i+1<<")="<<keys[i]<<endl;
  }*/
  vector<long long> stuff(upper,-1);
  stuff[1]=1;
  for(long long i = 2; i < upper; i++)
  {
    stuff[i]=stuff[i-1]+stuff[i-2];
  }
  for(long long i = 1; i < upper; i++)
  {
    cout << "fib("<<i<<")="<<stuff[i]<<endl;
  }


}
