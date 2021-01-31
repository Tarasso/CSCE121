#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

//coffee prices in cents per pound

const int bins = 20;

//prints histogram
void createHisto(vector<float>& nums, int size, float max, float min)
{
  int freqs[bins] = {0};
  float increment = (max-min)/bins; //range of each bin
  //each bin is represented by an index of freqs
  //the num in each freq is increased by 1 for each num in that range
  for(int i = 0; i < size; i++)
  {
    int binNumber = ceil((nums.at(i)-min)/increment);
    freqs[binNumber] += 1;
  }
  float lower = min;
  float upper = min + increment;
  //prints the histogram
  for(int i = 0; i < bins; i++)
  {
    cout << fixed << setprecision(3) << lower << " - " << fixed << setprecision(3) << upper;
    int count = freqs[i];
    while (count > 0)
    {
      cout << "*";
      count--;
    }
    cout << endl;
    lower += increment;
    upper += increment;
  }
}


int main(int charc, char** argv)
{
  //initialize variables
  vector<float> nums;
  int count = 0;
  float sum = 0.0;
  float min = 1000000;
  float max = -1000000;
  float squaredSum = 0;

  //read from file
  ifstream input;
  input.open(argv[1]);
  float num;
  while(input>>num)
  {
    nums.push_back(num);
    count++;
    sum += num;
    squaredSum += num * num;
    if (num>max) max = num;
    if (num<min) min = num;
  }

  //calculate and print key vaules
  float mean = sum/count;
  float stdev = sqrt((squaredSum/count)-mean*mean);
  cout << "num vals: " << count << endl;
  cout << "mean: " << mean << endl;
  cout << "std: " << stdev << endl;
  cout << "range: " << min << " - " << max << endl;
  int size = nums.size();
  createHisto(nums, size, max, min);
}
