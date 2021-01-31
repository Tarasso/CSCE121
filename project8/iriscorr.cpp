#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <exception>
#include "matrix.hpp"

using namespace std;

struct flower
{
  float sepalL;
  float sepalW;
  float petalL;
  float petalW;
  string species;
};

vector<flower> readData(string fileName, string targetSpecies)
{
  vector<flower> flowers;
  ifstream input;
  input.open(fileName);
  if(input.fail())
    cout << "Could not open file" << endl;
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

    if(tempFlower.species==targetSpecies)
      flowers.push_back(tempFlower);

  }
  return flowers;
}

float calcColMean(Matrix mat, int col)
{
  float sum = 0;
  int count = mat.rows;
  for(int i = 0; i < mat.rows; i++)
  {
    sum += mat.get(i,col);
  }
  return sum/count;
}

void centerData(Matrix mat)
{
  for(int i = 0; i < 4; i++)
  {
    float mean = calcColMean(mat,i);
    //cout << "mean" << i << ":" << mean << endl;
    for(int j = 0; j < mat.rows; j++)
    {
      mat.set(j,i,(mat.get(j,i)-mean));
    }
  }
}

int main(int argc, char** argv)
{
  if(argc!=3)
  {
    cout << "Please enter a valid command" << endl;
    cout << "./iriscorr <file to read from> <target species>" << endl;
  }
  else
  {
    vector<flower> flowers = readData(argv[1],argv[2]);
    Matrix mat(flowers.size(),4);

    for(int i = 0; i < flowers.size(); i++)
    {
      mat.set(i,0,flowers[i].sepalL);
      mat.set(i,1,flowers[i].sepalW);
      mat.set(i,2,flowers[i].petalL);
      mat.set(i,3,flowers[i].petalW);
    }

    centerData(mat);
    Matrix trans = mat.transpose();
    Matrix cov = trans.prod(mat);
    Matrix corr = cov.calcCorr();
    cout << endl;
    corr.print();
  }
}
