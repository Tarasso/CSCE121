#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

//Iterative Function to create power set
vector < vector<string> > combosIter(vector<string> list, int size)
{
  vector< vector<string> > allSubSets;
  int combos = pow(2,size);
  for(int comboNum = 0; comboNum < combos; comboNum++)
  {
    vector<string> subSet;
    for(int wordIndex = 0; wordIndex < size; wordIndex++)
    {
      int include = comboNum & (1 << wordIndex);
      if(include)
      {
        subSet.push_back(list[wordIndex]);
      }
    }
    allSubSets.push_back(subSet);
  }
  return allSubSets;
}

vector < vector<string> > answer; // To store recursive function's output
// Function that does the work recursively creating power set
void helper(vector<string> words, int index, vector<string> curr)
{
  int size = words.size();
  if(index==size)
    {
      answer.push_back(curr);
    }
  else
  {
    helper(words, index+1, curr);
    curr.push_back(words.at(index));
    helper(words, index+1, curr);

  }
}

// Calls the helper function and returns a vector containing all vecotrs of subsets
vector < vector<string> > combosRecur(vector<string> words)
{
  helper(words,0,vector<string>());
  return answer;
}


int main(int argc, char** argv)
{
  // Open and check file
  ifstream input;
  input.open(argv[1]);
  if(!input.is_open())
    cout << "Please run the program with a file to read from." << endl;
  else
  {
    //Store set
    vector<string> words;
    string word;
    while(input>>word)
      words.push_back(word);

    //Iterative call
    cout << "Iterative:" << endl;
    vector< vector<string> > subsets = combosIter(words,words.size());
    for(int i = 0; i < subsets.size(); i++)
      {
        for(int j = 0; j < subsets.at(i).size(); j++)
        {
          cout << subsets.at(i).at(j) << " ";
        }
        cout << endl;
      }

    //Recursive call
    cout << "Recursive:" << endl;
    subsets = combosRecur(words);
    for(int i = 0; i < subsets.size(); i++)
      {
        for(int j = 0; j < subsets.at(i).size(); j++)
        {
          cout << subsets.at(i).at(j) << " ";
        }
        cout << endl;
      }
    }
  }
