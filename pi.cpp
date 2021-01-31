#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

struct point
{
  float x;
  float y;
};

int main()
{
  int numPoints = 1000000000;
  int insideCircle = 0;
  vector<point> points;
  vector<float> distances;
  srand(time(NULL));
  for(int i = 1; i <= numPoints; i++)
  {
    point tempPoint;
    tempPoint.x = 2.0*(rand()/(float)RAND_MAX)-1.0;
    tempPoint.y = 2.0*(rand()/(float)RAND_MAX)-1.0;
    points.push_back(tempPoint);
    float distance = sqrt(tempPoint.x*tempPoint.x+tempPoint.y*tempPoint.y);
    distances.push_back(distance);
    if(distance<=1)
      insideCircle++;
    float fraction = (float)insideCircle/i;
    if(log10(i)==floor(log10(i)))
      cout << "iter: " << i << " , pi ~= " << 4*fraction << endl;
  }
}
