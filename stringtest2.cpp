#include <iostream>
#include <cctype>

using namespace std;

int main()
{
 string line;
 cout << "# ";
 while(getline(cin,line))
 {
  cout << line << endl;
  cout << "length = " << line.size() << endl;
  if(line.find('a')!=string::npos)
  {
  cout << "position of 'a' is " << line.find('a') << endl;;
  }
  string out;
  for(int i = 0; i < line.size(); i++)
  {
   out += toupper(line[i]);
  }
  cout << out << endl;
  cout << "# ";
 } 
}

