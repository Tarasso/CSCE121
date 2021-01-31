#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

//everything is working except equations with only 1 root, segmentation fault

vector<float> calcRoots(float a, float b, float c)
{
 vector<float> roots;
 float discriminant = pow(b,2)-4*a*c;
 cout << "discrim is: " << discriminant << endl;
 if(discriminant<0)
  return vector<float>();
 else if (discriminant==0.0)
  {
    cout << "Discrim is 0" << endl;
    float root = -b/(2*a);
    if(root==-0)
     root=0;

     cout << root << endl;
    roots[0] = -b/(2*a);
    cout << roots[0] << endl;
    return roots;
  }
  else
  {
    float root1 = (-b+sqrt(pow(b,2)-4*a*c))/(2*a);
    //cout << "1: " << root1 << endl;
    float root2 = (-b-sqrt(pow(b,2)-4*a*c))/(2*a);
    //cout << "2: " << root2 << endl;
    roots.push_back(root1);
    roots.push_back(root2);
    return roots;
  }
}

void printRoots(vector<float> roots)
{
 if(roots.empty())
 {
   cout << "Imaginary Roots" << endl;
 }
 else if(roots.size()==1)
 {
   cout << roots[0] << endl;
 }
 else
 {
   cout << roots[0] << " " << roots[1] << endl;
 }

}

int main(int charc, char** argv)
{
 float a = atof(argv[1]);
 float b = atof(argv[2]);
 float c = atof(argv[3]);
 vector<float> roots;
 roots = calcRoots(a,b,c);
 cout << "Im having problems" << endl;
 printRoots(roots);
}
