#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//This program uses Newton's method to approximate a sqrt

//accuracy tolerance
const float tol = .00001;

//recursive method to calculate sqrt
float sqrtRecur(float num1, float guess, float recurPrevDiff=9999999)
{
  float guess2 = guess - ((guess*guess-num1) / (2*guess));
  //default case
  if(recurPrevDiff < fabs(guess2-guess)) return -1;
  if(fabs(guess2-guess)<tol) return guess2;
  cout << "recursive estimate: " << fixed << setprecision(5) << guess2 << endl;
  return sqrtRecur(num1,guess2);
}

int main()
{
  float num;
  float guess;
  float difference = 9999999;
  int iterations = 1;

  //store values
  cout << "Please enter a number to evaluate the square root of: "; cin >> num;
  cout << "Please enter a guess of the square root: "; cin >> guess;

  //temp variable to keep a copy of guess for recurSqrt
  float holdGuess = guess;

  float prevDiff = 9999999;

  //iterative method for calculating sqrt
  while(difference > tol)
  {
    float guess2 = guess - ((guess*guess-num) / (2*guess));
    cout << "iter: " << iterations << ", est: " << fixed << setprecision(5) << guess << endl;
    difference = fabs(guess2-guess);
    if(difference > prevDiff)
    {
      cout << "Diverging" << endl;
      break;
    }
    else
      prevDiff = difference;

    guess = guess2;
    iterations++;
  }

  cout << "[iterative] sqrt(" << num << ") = " << guess << endl << endl;

  //call recursive method
  cout << "recursive estimate: " << num << endl;
  float est = sqrtRecur(num,holdGuess);
  if(est == -1)
    cout << "Diverging" << endl;
  else
    cout << "[recursive] sqrt(" << num << ") = " << fixed << setprecision(5) << est << endl << endl;

  //verifying print statements from built in commands
  float builtIn = sqrt(num);
  cout << "[built-in] sqrt(" << num << ") = " << fixed << setprecision(5) << builtIn << endl;
  cout << "[verifying] " << builtIn << "^2 = " << builtIn*builtIn << endl << endl;
}
