all: test test-kec morseex minimal
CXX = g++
CXXFLAGS = -O -Wall -Wextra -pedantic -std=c++11
LINK.o = $(CXX)
test:test.o
test.o:test.cpp map.hpp
test-kec:test-kec.o
test-kec.o:test-kec.cpp map.hpp
morseex:morseex.o
morseex.o:morseex.cpp map.hpp
minimal:minimal.o
minimal.o:minimal.cpp map.hpp
clean:
	\rm *.o test test-kec morseex minimal
