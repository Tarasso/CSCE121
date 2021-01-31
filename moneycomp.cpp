#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;

struct DEGREE
{
  string title;
  int startingMedian;
  int midcareerMedian;
  float percentChange;
  int midcareer10percentile;
  int midcareer25percentile;
  int midcareer75percentile;
  int midcareer90percentile;
};

int highestSartingSalary(const DEGREE a, const DEGREE b)
{
  return a.startingMedian>b.startingMedian;
}

int highestChange(const DEGREE a, const DEGREE b)
{
  return a.percentChange>b.percentChange;
}

vector<string> split(string s, char c)
{
  istringstream ss(s);
  string token;
  vector<string> tokens;
  while(getline(ss,token,c))
    tokens.push_back(token);
  return tokens;
}

int main(int argc, char** argv)
{
  ifstream file;
  file.open(argv[1]);
  if(!file.is_open()) cout << "Could not open file" << endl;
  else
  {
    vector<DEGREE> degrees;
    string line;
    getline(file,line);
    getline(file,line);
    while(getline(file,line))
    {
      vector<string> words = split(line,',');
      DEGREE temp;
      temp.title = words[0];
      temp.startingMedian = stoi(words[1]);
      temp.midcareerMedian = stoi(words[2]);
      temp.percentChange = stof(words[3]);
      temp.midcareer10percentile = stoi(words[4]);
      temp.midcareer25percentile = stoi(words[5]);
      temp.midcareer75percentile = stoi(words[6]);
      temp.midcareer90percentile = stoi(words[7]);
      degrees.push_back(temp);
    }

    sort(degrees.begin(),degrees.end(),highestSartingSalary);
    for(int i = 0; i < degrees.size(); i++)
    {
      cout << degrees.at(i).title << ": " << degrees.at(i).startingMedian << endl;
    }
    cout << "-----------------------------" << endl;
    sort(degrees.begin(),degrees.end(),highestChange);
    for(int i = 0; i < degrees.size(); i++)
    {
      cout << degrees.at(i).title << ": " << degrees.at(i).percentChange << endl;
    }

  }
}
