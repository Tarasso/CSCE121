#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define N 20

int check(pair<int,int> pair1, pair<int,int> pair2)
{
  return pair1.second > pair2.second;
}

int main()
{
  //create list of random values
  vector<int> nums;
  srand(time(NULL));
  for(int i = 0; i < N; i++)
    nums.push_back(rand()%N);

  //prints values
  for(auto item : nums) //easy way to print
    cout << item << " ";
  //for(vector<int>::iterator iter = nums.begin(); iter!=nums.end();iter++) //hard way to print
    //cout << *iter << " ";
  cout << endl;

  cout << "len=" << nums.size() << endl;

  //remove 0's in vector
  int targ = 0;
  vector<int>::iterator pos = find(nums.begin(),nums.end(),targ);
  while(pos!=nums.end())
  {
    cout << "erasing " << targ << " at position " << pos-nums.begin()+1 << endl;
    nums.erase(pos);
    pos = find(nums.begin(),nums.end(),targ);
  }

  cout << "len=" << nums.size() << endl;

  //print sorted
  sort(nums.begin(),nums.end());
  for(auto item : nums)
    cout << item << " ";
  cout << endl;

  //print reserve order
  for(vector<int>::reverse_iterator x = nums.rbegin(); x!=nums.rend(); x++)
    cout << *x << " ";
  cout << endl;

  //calc frequency
  unordered_map<int,int> hash;
  for(auto item : nums)
  {
    if(hash.find(item)==hash.end())
      hash[item] = 1;
    else
      hash[item]++;
  }

  vector<pair<int,int> > pairs(hash.begin(),hash.end());
  sort(pairs.begin(),pairs.end());
  cout << "Num, Freq" << endl;
  for(int i = 0; i < pairs.size(); i++)
  {
    cout << pairs[i].first << " " << pairs[i].second << endl;
  }

  sort(pairs.begin(),pairs.end(),check);
  cout << "Sorted by freq" << endl;
  for(int i = 0; i < pairs.size(); i++)
  {
    cout << pairs[i].first << " " << pairs[i].second << endl;
  }

}
