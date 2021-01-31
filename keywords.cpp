#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <unordered_map>
#include <tuple>
#include <iomanip>

using namespace std;

int check(pair<string,int> pair1, pair<string,int> pair2)
{
  return pair1.second > pair2.second;
}

int sortInfo(tuple<string,int,float,int,float,float,float> one, tuple<string,int,float,int,float,float,float> two)
{
  return get<6>(one) > get<6>(two);
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

void toLowerCase(string &str)
{
  int len = str.size();
  for(int i = 0; i < len; i++)
  {
    str[i] = tolower(str[i]);
  }
}

vector<string> clean(vector<string> words)
{
  vector<string> cleanedWords;
  for(int i = 0; i < words.size(); i++)
  {
    string word = words[i];
    toLowerCase(word);
    word.erase(remove_if(word.begin(), word.end(), [](char c) { return !isalpha(c) && c!='-'; } ), word.end());
    if(word!="")
      cleanedWords.push_back(word);
  }

  return cleanedWords;
}

vector<string> readFile(string fileName)
{
  vector<string> allWords;
  ifstream file;
  file.open(fileName);
  if(file.fail())
    cout << "could not open file " << fileName << endl;
  string line;
  while(getline(file,line))
  {
    vector<string> lineWords = split(line,' ');
    for(int i = 0; i < lineWords.size(); i++)
      allWords.push_back(lineWords[i]);
  }
  return allWords;
}

unordered_map<string,int> makeHash(vector<string> words)
{
  unordered_map<string,int> hash;
  for(auto word : words)
  {
    if(hash.find(word)==hash.end())
      hash[word] = 1;
    else
      hash[word]++;
  }
  return hash;
}


int main(int argc, char** argv)
{
  if(argc==2)
  {
    vector<string> words = readFile(argv[1]);
    words = clean(words);
    unordered_map<string,int> hash = makeHash(words);

    vector<pair<string,int> > pairs(hash.begin(),hash.end());
    sort(pairs.begin(),pairs.end(),check);
    cout << "Sorted by freq" << endl;
    for(int i = 0; i < pairs.size(); i++) //change num???
    {
      cout << pairs[i].second << " " << pairs[i].first<< endl;
    }

  }
  else if(argc==3)
  {
    vector<string> allWords = readFile(argv[1]);
    allWords = clean(allWords);
    unordered_map<string,int> allHash = makeHash(allWords);
    vector<pair<string,int> > allPairs(allHash.begin(),allHash.end());
    int numAllWords = allWords.size();

    vector<string> partWords = readFile(argv[2]);
    partWords = clean(partWords);
    unordered_map<string,int> partHash = makeHash(partWords);
    vector<pair<string,int> > partPairs(partHash.begin(),partHash.end());
    int numPartWords = partWords.size();

    vector< tuple<string,int,float,int,float,float,float> > wordInfo;

    //create tuple for each word
    for(int i = 0; i < partPairs.size(); i++)
    {
      string tempWord = partPairs[i].first;
      int localOccur = partPairs[i].second;
      int totalOccur = allHash[tempWord];
      float localFreq = (float)localOccur/numPartWords;
      float freq = (float)totalOccur/numAllWords;
      float expect = numPartWords * freq;
      float enrich = (localOccur+5) / (expect+5);
      tuple<string,int,float,int,float,float,float> temp = make_tuple(tempWord,localOccur,localFreq,totalOccur,freq,expect,enrich);//(tempWord,totalOccur,localOccur);
      wordInfo.push_back(temp);
    }
    sort(wordInfo.begin(),wordInfo.end(),sortInfo);
    cout << left << setw(15) << "WORD" << left << setw(10) << "num(doc)" << left << setw(15) << "freq(doc)";
    cout << left << setw(10) << "num(all)" << left << setw(15) << "freq(all)" << left << setw(10) << "expected" << left << setw(10) << "ratio" << endl;
    for(int i = 0; i < wordInfo.size(); i++)
    {
      string name;
      int localOccur;
      float localFreq;
      int totalOccur;
      float totalFreq;
      float expect;
      float enrich;
      tie(name,localOccur,localFreq,totalOccur,totalFreq,expect,enrich) = wordInfo[i];
      cout << setw(15) << name << setw(10) << localOccur << fixed << setprecision(6) << setw(15) << localFreq  << setw(10) << totalOccur;
      cout << setw(15) << totalFreq << setprecision(1) << setw(10) << expect << setprecision(4) << enrich << endl;
    }

  }
  else
  {
    cout << "Please enter ./keywords <text file> to analyze a collection" << endl;
    cout << "or" << endl;
    cout << "Please enter ./keywords <text file1> <text file2> to analyze document text file 2 within the context of text file 1" << endl;
  }
}
