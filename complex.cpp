#include<iostream>
#include<cmath>

using namespace std;

class Complex
{
private:
  float a;
  float b;
public:
  Complex(float x, float y): a(x), b(y) {}
  void print() {cout << a << "+" << b << "i" << endl;}
  float magnitude() {return sqrt(a*a+b*b);}
  Complex sum(Complex e) {return Complex(a+e.a,b+e.b);}
  Complex product(Complex e) {return Complex(a*e.a-b*e.b,b*e.a+a*e.b);}
};

int main()
{
  Complex P(3,2);
  Complex Q(-1,5);
  P.print();
  cout << P.magnitude() << endl;
  P.sum(Q).print();
  P.product(Q).print();
}
