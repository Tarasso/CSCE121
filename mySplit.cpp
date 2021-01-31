#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>

using namespace std;

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
    string line;
    while(getline(file,line))
    {
      vector<string> words = split(line,':');
      cout << words[0] << " is the host of " << words[1] << endl;
    }

  }
}
