#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const float tol = .00001;

float sqrtRecur(float num1, float guess)
{
  //cout << "num: " << num1 << "guess: " << guess << endl;
  float guess2 = guess - ((guess*guess-num1) / (2*guess));
  if(fabs(guess2-guess)<tol) {return guess2;}
  else
  {
    cout << "recursive estimate: " << fixed << setprecision(5) << guess2 << endl;
    //cout << "kyle" << endl;
    return sqrtRecur(num1,guess2);

  }
}

int main()
{
  float num;
  float guess;
  float difference = 9999999;
  int iterations = 1;

  cout << "Please enter a number to evaluate the square root of: "; cin >> num;
  cout << "Please enter a guess of the square root: "; cin >> guess;
  float holdGuess = guess;
  while(difference > tol)
  {
    float guess2 = guess - ((guess*guess-num) / (2*guess));
    cout << "iter: " << iterations << ", est: " << fixed << setprecision(5) << guess << endl;
    difference = fabs(guess2-guess);
    guess = guess2;
    iterations++;
  }
  cout << "[iterative] sqrt(" << num << ") = " << guess << endl << endl;

  cout << "recursive estimate: " << num << endl;
  float est = sqrtRecur(num,holdGuess);
  cout << "[recursive] sqrt(" << num << ") = " << fixed << setprecision(5) << est << endl << endl;

  float builtIn = sqrt(num);
  cout << "[built-in] sqrt(" << num << ") = " << fixed << setprecision(5) << builtIn << endl;
  cout << "[verifying] " << builtIn << "^2 = " << builtIn*builtIn << endl << endl;
}
