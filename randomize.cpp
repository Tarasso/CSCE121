#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int main(int charc, char** argv)
{
  ifstream input;
  input.open(argv[1]);
  string word;
  vector<string> list;
  while(input>>word)
    list.push_back(word);

  vector<string> copyList = list;

  srand(time(NULL));
  
  for(int i = 0; i<copyList.size(); i++)
  {
    int randIndex = rand()%(copyList.size());
    string temp = copyList[i];
    copyList[i] = copyList[randIndex];
    copyList[randIndex] = temp;
  }

  int i = 0;
  while(i < copyList.size())
  {
    cout << copyList[i++] << endl;
  }
}
