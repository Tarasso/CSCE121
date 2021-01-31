#include<iostream>
#include<cmath>
#include<vector>
#include<stdlib.h>

using namespace std;

vector<long long int> trialFactor(long long int num)
{
  long long int upperBound = ceil(sqrt(num));
  vector<long long int> factors;
  for(long long int i = 2; i <= upperBound; i++)
  {
    if(num%i==0)
    {
      factors.push_back(i);
      num /= i;
    }
  }
  factors.push_back(num);
  return factors;
}

vector<long long int> fermatFactor(long long int num)
{
  vector<long long int> factors;
  long long int start = ceil(sqrt(num));
  for(long long int i = start; i < num/2; i++)
  {
    long long int test = i * i - num;
    if(sqrt(test)==floor(sqrt(test)))
    {
      factors.push_back(i+sqrt(test));
      factors.push_back(i-sqrt(test));
    }

  }
  return factors;
}

int main(int argc, char** argv)
{
  long long int num = atoi(argv[1]);
  vector<long long int> factors = trialFactor(num);
  cout << "Trial Testing" << endl;
  if (factors[0]==num) cout << num << " is prime";
  else
  {
    cout << "Factors of " << num << " are: ";
    for(int i = 0; i < factors.size(); i++)
    {
      cout << factors[i] << " ";
    }
  }
  cout << endl;


  factors = fermatFactor(num);
  cout << "Fermat's Method Testing" << endl;
  if (factors[0]==num) cout << num << " is prime";
  else
  {
    cout << "Factors of " << num << " are: ";
    for(int i = 0; i < factors.size(); i++)
    {
      cout << factors[i] << " ";
    }
  }
  cout << endl;

}
