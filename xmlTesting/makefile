all: readXML

readXML: readXML.o
	g++ -o readXML readXML.o tinyxml2/libtinyxml2.a

readXML.o: readXML.cpp
	g++ -std=c++11 -c readXML.cpp
