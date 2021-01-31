#include <iostream>
#include <cmath>

using namespace std;

const float PI = 3.14159;

float distance(float x1, float y1, float x2, float y2)
{
  float dist = sqrt(pow((x2-x1),2) + pow((y2-y1),2));
  return dist;
}


void centerOfMass(float points[][2], int size, float& cx, float& cy)
{
  float xsum = 0;
  float ysum = 0;
  for (int i = 0; i < size; i++)
  {
    xsum += points[i][0];
    ysum += points[i][1];
  }
  cx = xsum/size;
  cy = ysum/size;
}

//farthest from the center of Mass
void farFromCenter(float points[][2], int size, float& cx, float& cy)
{
  float maxDist = 0;
  float tempDist = 0;
  int index = 0;
  for (int i = 0; i < size; i++)
  {
    tempDist = distance(cx,cy,points[i][0],points[i][1]);
    if (tempDist > maxDist)
    {
      maxDist = tempDist;
      index = i;
    }
  }
  cout << "Point (" << points[index][0] << "," << points[index][1] << ") is the farthest from the center of mass with distance " << maxDist << endl;
}

float toRadians(float degrees)
{
  return degrees*(PI/180);
}

void rotate(float x, float y, float theta)
{
  float rx = 0.0;
  float ry = 0.0;
  theta = toRadians(theta);
  rx = x*cos(theta)-y*sin(theta);
  ry = y*cos(theta)+x*sin(theta);
  cout << "(" << x << "," << y << ") rotated 45 degrees is: " << "(" << rx << "," << ry << ")" << endl;
}

int main()
{
  const int rows = 4;
  const int cols = 2;
  float coords[rows][cols] = {0,0, 5,-1, 10,0, 5,10};
  for(int i = 0; i < rows; i++)
  {
    cout << "(" << coords[i][0] << "," << coords[i][1] << ") has magnitude: " << distance(0,0,coords[i][0],coords[i][1]) << endl;
  }
  float cx = 0.0;
  float cy = 0.0;
  centerOfMass(coords,rows,cx,cy);
  cout << "Center of Mass: (" << cx << "," << cy << ") has magnitude " << distance(0,0,cx,cy) << endl;
  farFromCenter(coords,rows,cx,cy);
  for(int i = 0; i < rows; i++)
  {
    rotate(coords[i][0],coords[i][1],45);
  }
}
