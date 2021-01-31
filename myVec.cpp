#include "myVec.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

template <typename T>
myVec<T>::myVec()
{
  n = 0; //curent size
  max = 8; //max size
  v = new T[max];
}

template <typename T>
myVec<T>::myVec(int size)
{
  n = 0;
  max = 8;
  v = new T[size];
}

template <typename T>
myVec<T>::myVec(const myVec& copy)
{
  n = copy.n;
  max = copy.max;
  v = copy.v;
}

template <typename T>
void myVec<T>::append(T num)
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

template <typename T>
int myVec<T>::at(int spot)
{
  return v[spot];
}

template <typename T>
int myVec<T>::operator [] (int spot)
{
  return v[spot];
}

template <typename T>
myVec<T> myVec<T>::operator + (myVec<T> vec2)
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

template <typename T>
void myVec<T>::reverse()
{
  for(int i = 0; i < n/2-1; i++)
  {
    T temp = v[i];
    v[i] = v[n-1-i];
    v[n-1-i] = temp;
  }
}

template <typename T>
int myVec<T>::find(int target)
{
  for(int i = 0; i < n; i++)
  {
    if(v[i]==target)
      return i;
  }
  return -1;
}

template <typename T>
int myVec<T>::size()
{
  return n;
}

template <typename T>
string myVec<T>::toString()
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

template <typename T>
void myVec<T>::print()
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

/*myVec::~myVec()
{
  delete pointer to heap
}*/
