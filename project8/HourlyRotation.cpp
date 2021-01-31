#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include "matrix.hpp"

using namespace std;

#define PI 3.1415928

vector<string> split(string s, char c)
{
  istringstream ss(s);
  string token;
  vector<string> tokens;
  while(getline(ss,token,c))
    tokens.push_back(token);
  return tokens;
}

class Point2D : public Matrix
{
public:
  float x;
  float y;
  Point2D(float val1, float val2) : Matrix(1,2)
  {
    x = val1;
    y = val2;
    set(0,0,x);
    set(0,1,y);
  }
};

class Rot2D : public Matrix
{
public:
  float theta;
  Rot2D(float val1) : Matrix(2,2)
  {
    theta = val1*PI/180;
    set(0,0,cos(theta));
    set(0,1,-sin(theta));
    set(1,0,sin(theta));
    set(1,1,cos(theta));
  }
};

vector<Point2D> readData(string fileName)
{
  vector<Point2D> points;
  ifstream input;
  input.open(fileName);

  if(input.fail())
    cout << "Could not open file" << endl;
  string line;
  while(getline(input,line))
  {
    vector<string> vals = split(line,' ');
    float val1 = stof(vals[0]);
    float val2 = stof(vals[1]);
    Point2D temp(val1,val2);
    points.push_back(temp);
  }
  return points;
}

int main(int argc, char** argv)
{
  if(argc!=2)
  {
    cout << "Please enter a correct input" << endl;
    cout << "./HourlyRotation <filename>" << endl;

  }
  else
  {
    vector<Point2D> points = readData(argv[1]);
    for(int i = 1; i <= 12; i++)
    {
      Rot2D rot(i*30);
      cout << "----------------" << endl;
      cout << "hour=" << i << endl;
      for(int j = 0; j < points.size(); j++)
      {
        points[j].prod(rot).print();
      }
    }
  }
}
