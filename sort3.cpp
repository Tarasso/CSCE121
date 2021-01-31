#include<iostream>

using namespace std;

template<typename T1>
void sortThree(T1 a, T1 b, T1 c)
{
  if(a>b)
  {
    T1 temp = a;
    a = b;
    b = temp;
  }
  if(b>c)
  {
    T1 temp = b;
    b = c;
    c = temp;
  }
  if(a>b)
  {
    T1 temp = a;
    a = b;
    b = temp;
  }

  cout << a << " " << b << " " << c << endl;
}

int main()
{
  int a = 7;
  int b = 3;
  int c = 20;
  sortThree(a,b,c);
  string aa = "gamma";
  string bb = "beta";
  string cc = "alpha";
  sortThree(aa,bb,cc);
}
