#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>;

using namespace std;

int main(int argc, char** argv)
{

 if (argc<3)
 {
  cout << "usage: area51 <length> <width>\n";
  exit(0);
 }

 float length = atof(argv[1]);
 float width = atof(argv[2]);

 cout << "area: " << length * width << endl;

 /*

 cout << "num args:" << argc;
 cout << "arguments:" << endl;

 for(int i=0; i<argc; i++)
 {
  cout << argv[i] << endl;
 }

 
 cout << "area51" << endl;
 cout << "input length: ";
 float length;
 cin >> length;

 cout << "input width: ";
 float width;
 cin >> width;

 cout << "length=" << length << endl;
 cout << "width=" << width << endl;
 cout << "area=" << length*width << endl;

 

 string sentence;
 cout << "input a sentence: ";
 getline(cin, sentence);
 cout << sentence.size() << endl;
 
 istringstream ss(sentence);
 string w;
 while (ss >> w) cout << w << endl;

 */

}
