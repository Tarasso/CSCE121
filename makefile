all: examples hello showbits area area51 circle stringtest1 stringtest2 show_words weather myGrep wordCount calendar gcd quadratic fact fib histo arrays geometry pointers vending iris newtonSqrt subsets randomize pi mySplit genomics sortdata moneycomp factor cities complex testVec polynomials shapes sort3 scores keywords iterators listPractice expressions

expressions: expressions.cpp
	g++ -std=c++11 -o expressions expressions.cpp

listPractice: listPractice.cpp
	g++ -std=c++11 -o listPractice listPractice.cpp

iterators: iterators.cpp
	g++ -std=c++11 -o iterators iterators.cpp

keywords: keywords.cpp
	g++ -std=c++11 -o keywords keywords.cpp

scores: scores.cpp
	g++ -std=c++11 -o scores scores.cpp

sort3: sort3.cpp
	g++ -o sort3 sort3.cpp

shapes: shapes.cpp
	g++ -o shapes shapes.cpp

polynomials: polynomials.cpp
	g++ -std=c++11 -o polynomials polynomials.cpp

testVec: testVec.o
	g++ -o testVec testVec.o

testVec.o: testVec.cpp myVec.hpp
	g++ -c testVec.cpp

myVec.o: myVec.cpp myVec.hpp
	g++ -std=c++11 -c myVec.cpp

complex: complex.cpp
	g++ -o complex complex.cpp
cities: cities.cpp
	g++ -std=c++11 -o cities cities.cpp

factor: factor.cpp
	g++ -o factor factor.cpp

moneycomp: moneycomp.cpp
	g++ -std=c++11 -o moneycomp moneycomp.cpp

sortdata: sortdata.cpp
	g++ -o sortdata sortdata.cpp

genomics: genomics.cpp
	g++ -std=c++11 -o genomics genomics.cpp

mySplit: mySplit.cpp
	g++ -o mySplit mySplit.cpp

pi: pi.cpp
	g++ -o pi pi.cpp

randomize: randomize.cpp
	g++ -o randomize randomize.cpp

subsets: subsets.cpp
	g++ -o subsets subsets.cpp

newtonSqrt: newtonSqrt.cpp
	g++ -o newtonSqrt newtonSqrt.cpp

iris: iris.cpp
	g++ -std=c++11 -o  iris iris.cpp

vending: vending.cpp
	g++ -o vending vending.cpp

pointers: pointers.cpp
	g++ -o pointers pointers.cpp

geometry: geometry.cpp
	g++ -o geometry geometry.cpp

arrays: arrays.cpp
	g++ -o arrays arrays.cpp

histo: histo.cpp
	g++ -o histo histo.cpp


fact: fact.o integerFunctions.o
	g++ -o fact fact.o integerFunctions.o

gcd.o: gcd.cpp integerFunctions.hpp
	g++ -c gcd.cpp

fib.o: fib.cpp integerFunctions.hpp
	g++ -c fib.cpp

fact.o: fact.cpp integerFunctions.hpp
	g++ -c fact.cpp

fib: fib.cpp
	g++ -o fib fib.cpp

integerFunctions.o: integerFunctions.cpp integerFunctions.hpp
	g++ -c integerFunctions.cpp

quadratic: quadratic.cpp
	g++ -o quadratic quadratic.cpp

gcd: gcd.o integerFunctions.o
	g++ -o gcd gcd.o integerFunctions.o

calendar: calendar.cpp
	g++ -o calendar calendar.cpp

wordCount: wordCount.cpp
	g++ -o wordCount wordCount.cpp

myGrep: myGrep.cpp
	g++ -o myGrep myGrep.cpp

weather: weather.cpp
	g++ -o weather weather.cpp

show_words: show_words.cpp
	g++ -o show_words show_words.cpp

stringtest2: stringtest2.cpp
	g++ -o stringtest2 stringtest2.cpp

stringtest1: stringtest1.c
	g++ -o stringtest1 stringtest1.c

circle: circle.cpp
	g++ -o circle circle.cpp

area51: area51.cpp
	g++ -o area51 area51.cpp

area: area.cpp
	g++ -o area area.cpp

showbits: showbits.cpp
	g++ -o showbits showbits.cpp

examples: examples.cpp
	g++ -o examples examples.cpp

hello: hello.cpp
	g++ -o hello hello.cpp
