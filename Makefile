PermutationGenerator: PermutationGenerator.o
	g++ -Wall -o PermutationGenerator PermutationGenerator.o

PermutationGenerator.o: PermutationGenerator.cpp
	g++ -Wall -c PermutationGenerator.cpp

test: test.o
	g++ -Wall -o test test.o

test.o: test.cpp
	g++ -Wall -I. -c test.cpp
