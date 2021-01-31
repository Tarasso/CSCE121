#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class Shape
{
public:
  virtual float area()
  {
    return 0;
  }
};

class Circle : public Shape
{
private:
  float rad;
public:
  Circle(float r) { rad = r;}
  float area()
  {
    return 3.14*rad*rad;
  }
};

class Rectangle : public Shape
{
private:
  float height;
  float width;
public:
  Rectangle(float h, float w) { height = h; width = w;}
  float area()
  {
    return width*height;
  }
};

class Triangle : public Shape
{
private:
  float a;
  float b;
  float c;
public:
  Triangle(float s1, float s2, float s3) { a = s1; b = s2; c = s3;}
  float area()
  {
    float s = (a + b + c)/2;
    float area = sqrt(s*(s-a)*(s-b)*(s-c));
    return area;
  }
};



int main()
{
  vector<Shape*> shapes;
  shapes.push_back(new Circle(4));
  shapes.push_back(new Rectangle(2,5));
  shapes.push_back(new Triangle(18,24,30));

  for(int i = 0; i < shapes.size(); i++)
  {
    cout << shapes[i]->area() << endl;
  }

}
