#include <iostream>

using namespace std;

int main()
{
 int x = 13;
 cout << "x=" << x << endl;

 for (int i=0; i<32; i++)
 {
  bool bit;
  bit=x%2;
  x/=2;
  cout << bit;
 }
}
