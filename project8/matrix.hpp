#include <iostream>
#include <vector>

using namespace std;

class Matrix
{
public:
  int rows;
  int cols;
  float* ray;
  int size;
  Matrix(int r, int c);
  Matrix(const Matrix& copy);
  void fillMat(vector<float> nums);
  float get(int r, int c);
  void set(int r, int c, float val);
  Matrix transpose();
  Matrix prod(Matrix other);
  Matrix calcCor(Matrix cov);
  Matrix calcCorr();
  void print();
};
