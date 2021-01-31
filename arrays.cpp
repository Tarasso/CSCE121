#include <iostream>

using namespace std;

void printArray(string array[],int size)
{
  for(int i = 0; i < size; i++)
  {
    cout << array[i] << " ";
  }
  cout << endl;
}

int find(string array[], int size, string target)
{
  for(int i = 0; i < size; i++)
  {
    if(array[i]==target) return i;
  }
  return -1;
}

void reverse(string array[],int size)
{
  string temp;
  for(int i = 1; i <= size/2; i++)
  {
    temp = array[size-i];
    array[size-i] = array[i-1];
    array[i-1] = temp;
  }
  printArray(array, size);
}

void circulate(string array[], int size, int shifts)
{
  string newArray[size];
  int place;
  for(int i = 0; i < size; i++)
  {
    place = i+shifts;
    if(place>=size) place = place-7;
    newArray[place] = array[i];
  }
  printArray(newArray,size);
}

void remove(string array[], int size, string day)
{
  int removedSize = size;
  string removed[size-1];
  int indexToRemove = find(array,size,day);
  int count = 0;
  for(int i = 0; i < size; i++)
  {
    if(i==indexToRemove) continue;
    removed[count++] = array[i];
  }
  removedSize--;

  if(find(removed,size-1,day)!=-1)
    remove(removed,size-1,day);
  else
    printArray(removed,removedSize);
}

int main()
{
  const int size = 7;
  string week[size] = {"Sun","Mon","Tues","Wed","Thurs","Fri","Sat"};
  cout << "Print: "; printArray(week,size);
  cout << "Wed = " << find(week,size,"Wed") << endl;
  cout << "Circulate: "; circulate(week,size,4);
  cout << "Wed Removed: "; remove(week,size,"Wed");
  cout << "Reversed: "; reverse(week,size);
}
