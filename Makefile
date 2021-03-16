PermutationGenerator: PermutationGenerator.o
	g++ -Wall -o PermutationGenerator PermutationGenerator.o

PermutationGenerator.o: PermutationGenerator.cpp
	g++ -Wall -c PermutationGenerator.cpp