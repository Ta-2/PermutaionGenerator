#ifndef PerH
#define PerH

#include <string>
#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

template<class U>
class PermutationGenerator{
private:
	vector<pair<bool, U>> source;
	vector<typename vector<pair<bool, U>>::iterator> itrs;
	vector<U> result;
	int stage = 0;
public:
	int all = 0;
	void AddElement(U add){
		source.push_back(make_pair(true, add));
		if(result.capacity() < source.size())result.reserve(source.size());
		if(itrs.capacity() < source.size())itrs.reserve(source.size());
	}
	void reset(){
		source.clear();
		Initialize();
	}
	void Initialize(){
		result.clear();
		itrs.clear();
		return;
	}
	void Gen(int extract = -1){
		Initialize();
		for(typename vector<pair<bool, U>>::iterator s = source.begin(); s != source.end() && extract; s++, extract--){
			result.push_back(s->second);
			s->first = false;
			itrs.push_back(s);
		}
		return;
	}
	bool nextPermutation(){
		typename vector<typename vector<pair<bool, U>>::iterator>::iterator it = itrs.end();
		for( typename vector<typename vector<pair<bool, U>>::iterator>::reverse_iterator rit = itrs.rbegin(); rit != itrs.rend(); rit++){
			typename vector<pair<bool, U>>::iterator elem = *rit;
			while(!elem->first && elem != source.end()) elem++;
 			result.pop_back();
			(*rit)->first = true;
			if(elem != source.end()){
				result.push_back(elem->second);
				elem->first = false;
				it = --rit.base();
				*it = elem;
				break;
			}
		}
		if(it == itrs.end())return false;
		auto s = source.begin();
		it++;
		while(it != itrs.end()){
			while(!s->first && s != source.end())s++;
			*it = s;
			s->first = false;
			result.push_back(s->second);
			it++;
		}
		return true;
	}
	void PrintAllPermutation(){
		Initialize();
		AllPermutation();
	}
	void AllPermutation(){
		if(stage == (int)source.size()){
			all++;
			for(auto r: result) cout << r;
			cout << endl;
			return;
		}
		for(typename vector<pair<bool, U>>::iterator s = source.begin(); s != source.end(); s++){
			if(s->first){
				stage++;
				result.push_back(s->second);
				s->first = false;
				AllPermutation();
				result.pop_back();
				s->first = true;
				stage--;
			}
		}
		return;
	}
	vector<pair<bool, U>>* Getsource(){
		return &source;
	}
	const vector<U>* GetResult (){
		return &result;
	}
	void PrintSource(){
		cout << "<<source>>: ";
		for(auto s: source)cout << s.second << ", ";
		cout << endl;
	}
	void PrintResult(){
		cout << "<<result>>: ";
		for(auto r: result)cout << r;
		cout << endl;
	}
};


#endif
