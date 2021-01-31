#include <string>
#include <iostream>

using namespace std;

template<typename T>
class myVec
{
public:
  myVec()
  {
    n = 0; //curent size
    max = 8; //max size
    v = new T[max];
  }
  myVec(int size)
  {
    n = 0;
    max = 8;
    v = new T[size];
  }
  myVec(const myVec& copy)
  {
    n = copy.n;
    max = copy.max;
    v = copy.v;
  }
  void append(T num)
  {
    if(n == max)
    {
      T *z = new T[max*2];
      for(int i = 0; i < n; i++)
      {
        z[i] = v[i];
      }
      delete v;
      v = z;
      max *= 2;
    }
    v[n] = num;
    n++;
  }
  void print()
  {
    cout << "[";
    for(int i = 0; i < n; i++)
    {
      cout<<v[i];
      if(i!=n-1)
        cout<<",";
    }
    cout << "]" << endl;
  }
  T at(int spot)
  {
    return v[spot];
  }
  int operator [] (int spot)
  {
    return v[spot];
  }
  int size()
  {
    return n;
  }
  string toString()
  {
    string ret = "[";
    for(int i = 0; i < n; i++)
    {
      ret += to_string(v[i]);
      if(i!=n-1)
        ret += ",";
    }
    ret += "]";
    return ret;
  }
  myVec operator + (myVec vec2)
  {
    T newSize = n + vec2.n;
    myVec ret(newSize);
    for(int i = 0; i < n; i++)
    {
      ret.append(v[i]);
    }
    for(int i = 0; i < vec2.n; i++)
    {
      ret.append(vec2.v[i]);
    }
    return ret;
  }
  void reverse()
  {
    for(int i = 0; i < n/2-1; i++)
    {
      T temp = v[i];
      v[i] = v[n-1-i];
      v[n-1-i] = temp;
    }
  }
  int find(int target)
  {
    for(int i = 0; i < n; i++)
    {
      if(v[i]==target)
        return i;
    }
    return -1;
  }
  //~myVec();
private:
  int n;
  T* v;
  int max;
};
