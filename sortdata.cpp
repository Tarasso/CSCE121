#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<sstream>

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

int revcomp(const int& a, const int& b)
{
  return a>b;
}

int compstr(const string& a, const string& b)
{
  return a.size()<b.size();
}

int main(int argc, char** argv)
{
  ifstream file;
  file.open(argv[1]);
  if(!file.is_open()) cout << "Could not open first file" << endl;
  else
  {
    int num;
    vector<int> vec;
    while(file >> num)
      vec.push_back(num);
    sort(vec.begin(),vec.end());
    for(int i = 0; i < vec.size(); i++)
      cout << vec.at(i) << endl;
    cout << "-------------------------------" << endl;
    sort(vec.begin(),vec.end(),revcomp);
    for(int i = 0; i < vec.size(); i++)
      cout << vec.at(i) << endl;
    file.close();
  }

    string line = "A noble spirit embiggens the smallest man";
    vector<string> vecstr = split(line,' ');
    sort(vecstr.begin(),vecstr.end(),compstr);
    for(int i = 0; i < vecstr.size(); i++)
      cout << vecstr.at(i) << endl;

}
