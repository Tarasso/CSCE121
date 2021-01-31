#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const int P = 3;
const int Q = 5;

void printMat(int* x, int nrows, int ncols)
{
  for(int i = 0; i < nrows; i++)
  {
    for(int j = 0; j < ncols; j++)
      cout << setw(2) << *(x+(i*ncols)+j) << " ";
    cout << endl;
  }
  cout << endl;
}

int main()
{
  /*int N;
  cout << "Enter a integer: ";
  cin >> N;
  float *p = new float(N);
  for (int i = 0; i < N; i++)
  {
    //*(p+i) = sqrt(i); //pointer arithmetic
    p[i] = sqrt(i);
  }

  float sum = 0;
  for (int i = 0; i < N; i++)
  {
    //sum += *(p+i); //pointer arithmetic
    sum += p[i];
  }

  cout << "Sum of square roots: " << sum << endl;
  */

  int mat[P][Q];

  for(int i = 0; i < P; i++)
    for(int j = 0; j < Q; j++)
      mat[i][j] = 0;


  int *pointer = (int*)mat;
  for(int i = 0; i < P*Q; i++)
    *(pointer+i) = i+1;

  printMat(pointer,P,Q);

  }
