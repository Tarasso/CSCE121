#include <iostream>
#include <fstream>

using namespace std;

int main()
{
 ifstream input;
 input.open("data.txt");
 int num;
 int count = 0;
 int sum = 0;
 while(input >> num)
 {
  sum += num;
  count += 1;
 }
 cout << "mean of " << count << " temps is " << (float)sum/count << endl;
}
