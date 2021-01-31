#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
ifstream input;
input.open(argv[1]);
int word;
while (input >> word) cout << word << endl;
input.close();
}
