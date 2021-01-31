#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv)
{
    string test = "KYLE";
    for(int i = 0; i < test.size(); i++)
    {
      char * c = test.begin()+i;
      *c = tolower(*c);
    }
    cout << test << endl;
}
