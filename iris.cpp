#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct flower
{
  float sepalL;
  float sepalW;
  float petalL;
  float petalW;
  string species;
};

vector<flower> flowers;

void countSpecies(string target)
{
  int count = 0;
  for(int i = 0; i < flowers.size(); i++)
  {
    if(flowers.at(i).species==target)
      count++;
  }

  cout << "There are " << count << " " << target << " in this data set." << endl;

}

float calcMean(vector<float> nums)
{
  int count = 0;
  float sum = 0;
  for(int i = 0; i < nums.size(); i++)
  {
    sum += nums.at(i);
    count++;
  }
  return sum/count;
}

int main(int argc, char** argv)
{
  ifstream input;
  input.open(argv[1]);
  string line;
  while(input>>line)
  {
    flower tempFlower;
    istringstream ss(line);
    string word;
    getline(ss,word,',');
    tempFlower.sepalL = stof(word);
    getline(ss,word,',');
    tempFlower.sepalW = stof(word);
    getline(ss,word,',');
    tempFlower.petalL = stof(word);
    getline(ss,word,',');
    tempFlower.petalW = stof(word);
    getline(ss,word,',');
    tempFlower.species = word;
    flowers.push_back(tempFlower);
  }

  vector<float> sepalLengths;
  vector<float> sepalWidths;
  vector<float> petalLengths;
  vector<float> petalWidths;

  for(int i = 0; i < flowers.size(); i++)
    sepalLengths.push_back(flowers.at(i).sepalL);
  for(int i = 0; i < flowers.size(); i++)
    sepalWidths.push_back(flowers.at(i).sepalW);
  for(int i = 0; i < flowers.size(); i++)
    petalLengths.push_back(flowers.at(i).petalL);
  for(int i = 0; i < flowers.size(); i++)
    petalWidths.push_back(flowers.at(i).petalW);

  cout << "The mean of the sepal lengths is " << calcMean(sepalLengths) << endl;
  cout << "The mean of the sepal widths is " << calcMean(sepalWidths) << endl;
  cout << "The mean of the petal lengths is " << calcMean(petalLengths) << endl;
  cout << "The mean of the petal widths is " << calcMean(petalWidths) << endl;

  countSpecies("Iris-setosa");
  countSpecies("Iris-versicolor");
  countSpecies("Iris-virginica");

}
