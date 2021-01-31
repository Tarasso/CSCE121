#include <iostream>
#include <sstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

class Expr
{
  float val;
  enum KIND {ATOMIC,BINARY};
  KIND kind;
  Expr* left;
  Expr* right;
  char opr;

public:
  Expr(float x)
  {
    val = x;
    kind = ATOMIC;
  }
  Expr(Expr* a, char o, Expr* b)
  {
    left = a;
    opr = o;
    right = b;
    kind = BINARY;
  }
  string toString()
  {
    stringstream ss;
    if(kind==ATOMIC)
    {
      ss<<val;
    }
    else
    {

        ss<<"(";
        ss<<left->toString();
        ss<<opr;
        ss<<right->toString();
        ss<<")";
    }
    return ss.str();
  }
  float eval()
  {
    if(kind==ATOMIC)
    {
      return val;
    }
    else
    {
      if(opr=='+')
        return left->eval() + right->eval();
      if(opr=='-')
        return left->eval() - right->eval();
      if(opr=='*')
        return left->eval() * right->eval();
      if(opr=='/')
        return left->eval() / right->eval();
    }
  }

};

int main(int argc, char** argv)
{
  Expr A = Expr(5);
  Expr B = Expr(2);
  Expr C = Expr(&A,'*',&B);
  cout << setprecision(2) << C.toString() << "=" << C.eval() << endl;
  Expr D = Expr(4);
  Expr E = Expr(&C,'/',&D);
  cout << setprecision(2) << E.toString() << "=" << E.eval() << endl;

  Expr one = Expr(1);
  Expr two = Expr(2);
  Expr three = Expr(3);
  Expr four = Expr(4);

  Expr EE = Expr(new Expr(&one,'+',&two),'*',new Expr(&three,'+',&four));
  cout << setprecision(2) << EE.toString() << "=" << EE.eval() << endl;

  Expr F = Expr(&E,'/',&EE);
  cout << setprecision(2) << F.toString() << "=" << F.eval() << endl;
}
