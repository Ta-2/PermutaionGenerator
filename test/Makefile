test: test.o
	g++ -Wall -o test test.o -L../lib -lPerGen

test.o: test.cpp
	g++ -Wall -I../include -c test.cpp

.PHONY: clean rebuild
clean:
	rm *.o test

rebuild:
	-rm ../lib/libPerGen.a ../lib/*.o
	g++ -Wall -o ../lib/PermutationGenerator.o \
	-c ../src/PermutationGenerator.cpp
	ar rcs ../lib/libPerGen.a ../lib/PermutationGenerator.o
