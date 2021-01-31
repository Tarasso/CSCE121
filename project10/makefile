all: elevator

elevator: person.o elevator.o container.o floor.o car.o building.o
	g++ -o elevator person.o elevator.o container.o floor.o car.o building.o

building.o: building.cpp building.hpp container.hpp floor.hpp car.hpp person.hpp
	g++ -std=c++11 -c building.cpp

car.o: car.cpp car.hpp container.hpp person.hpp
	g++ -std=c++11 -c car.cpp

floor.o: floor.cpp floor.hpp container.hpp person.hpp
	g++ -std=c++11 -c floor.cpp

container.o: container.cpp person.hpp container.hpp
	g++ -std=c++11 -c container.cpp

elevator.o: elevator.cpp person.hpp container.hpp floor.hpp car.hpp building.hpp
	g++ -std=c++11 -c elevator.cpp

person.o: person.cpp person.hpp
	g++ -std=c++11 -c person.cpp
