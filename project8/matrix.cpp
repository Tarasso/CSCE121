#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include "matrix.hpp"

using namespace std;

Matrix::Matrix(int r, int c)
{
  rows = r;
  cols = c;
  size = r*c;
  ray = new float[size];
}

Matrix::Matrix(const Matrix& copy)
{
  rows = copy.rows;
  cols = copy.cols;
  size = copy.size;
  ray = copy.ray;
}

void Matrix::fillMat(vector<float> nums)
{
  for(int i = 0; i < size; i++)
  {
    ray[i] = nums[i];
  }
}

float Matrix::get(int r, int c)
{
  return ray[r*cols+c];
}

void Matrix::set(int r, int c, float val)
{
  ray[r*cols+c] = val;
}

Matrix Matrix::transpose()
{
  Matrix trans(cols,rows);
  vector<float> nums;
  float* newRay = new float[size];
  for(int i = 0; i < cols; i++)
  {
    for(int j = 0; j < rows; j++)
    {
      nums.push_back(get(j,i));
    }
  }
  trans.fillMat(nums);
  return trans;
}

Matrix Matrix::prod(Matrix other)
{
  if(cols!=other.rows)
  {
    cout << "Cannot multiply matricies" << endl;
    Matrix x(1,1);
    return x;
  }
  Matrix ret(rows,other.cols);
  for(int i =0; i < rows; i++)
  {
    for(int j = 0; j < other.cols; j++)
    {
      float point = 0;
      for(int k = 0; k < cols; k++)
        point += get(i,k)*other.get(k,j);
      ret.set(i,j,point);
    }
  }
  return ret;
}

Matrix Matrix::calcCorr()
{
  Matrix corrMat(rows,cols);
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < cols; j++)
    {
      float point = get(i,j);
      float value = point/(sqrt(get(i,i)*get(j,j)));
      corrMat.set(i,j,value);
    }
  }
  return corrMat;
}

void Matrix::print()
  {
    cout << fixed << setprecision(3);
    for(int i = 0; i < size; i++)
    {
      if(abs(ray[i])<.00001)
        cout << "0.000" << " ";
      else
        cout << ray[i] << " ";
      if((i+1)%cols==0)
        cout << endl;
    }
  }
