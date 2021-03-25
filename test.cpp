#include "PermutationGeneratorHeader.hpp"

int main(int argc, char *argv[]){
	int elems[] = {0, 1, 2, 3};
	PermutationGenerator<int*> *pg = new PermutationGenerator<int*>;
	
	for(int &a: elems) pg->AddElement(&a);
	pg->PrintSource();
	/*
	pg->PrintAllPermutation();
	cout << "all: " << pg->all << endl;
	*/
	pg->Gen();
	pg->PrintResult();
	int num = 1;
	while(pg->nextPermutation()){
		//pg->PrintResult();pg2		//error
		for(auto r: *(pg->GetResult())) cout << *r;
		cout << endl;
		num++;
	}
	cout << "all: " << num << endl;

	PermutationGenerator<char> *pg2 = new PermutationGenerator<char>;
	cout << "Permutation of \"CRYPTO\" " << endl;
	for(char &s: string("CRYPTO") )pg2->AddElement(s);
	pg2->PrintSource();
	pg2->AllPermutation();
	
	pg2->reset();
	cout << "Permutation of \"C\" " << endl;
	for(char &s: string("C") )pg2->AddElement(s);
	pg2->PrintSource();
	pg2->AllPermutation();
	
	pg2->reset();
	for(char &s: string("CR") )pg2->AddElement(s);
	pg2->PrintSource();
	pg2->AllPermutation();

	pg2->reset();
	for(char &s: string("CRYPTO") )pg2->AddElement(s);
	
	if(argc > 1)pg2->Gen((int)atoi(argv[1]));
	else pg2->Gen(3);
	num = 1;
	pg2->PrintResult();
	while(pg2->nextPermutation()){
		pg2->PrintResult();
		num++;
	}
	cout << "all: " << num << endl;
	
	return 0;
}
