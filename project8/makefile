all: iriscorr HourlyRotation

HourlyRotation: HourlyRotation.o matrix.o
	g++ -o HourlyRotation HourlyRotation.o matrix.o

HourlyRotation.o: HourlyRotation.cpp matrix.hpp
	g++ -std=c++11 -c HourlyRotation.cpp

iriscorr: iriscorr.o matrix.o
	g++ -o iriscorr iriscorr.o matrix.o

iriscorr.o: iriscorr.cpp matrix.hpp
	g++ -std=c++11 -c iriscorr.cpp

matrix.o: matrix.cpp matrix.hpp
	g++ -c matrix.cpp
