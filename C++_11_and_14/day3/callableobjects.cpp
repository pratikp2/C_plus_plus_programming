#include <iostream>
#include <vector>
#include <algorithm>
#include "number.h"
using namespace std;


int globalNumToFind;
vector<Number> globalResult;
void findNum(Number num){
	if(num.Value() > globalNumToFind)
		globalResult.push_back(num);
}

//Function Object class
class NumberFinder{
public:
	NumberFinder(int n, vector<Number>& r):numToFind(n), result(r){}
	void operator()(Number num){
		if(num.Value() > numToFind)
			result.push_back(num);
	}
private:	
	const int numToFind;
	vector<Number>& result; 
};


void main(){
	vector<int> intVect = {4,7,1,5,9,6};
	auto it = find(intVect.begin(), intVect.end(), 10);
	if(it != intVect.end())
		cout << "int found in the vector" << endl;
	else
		cout << "Didn't found the value in vector" << endl;

	vector<Number> numVect = {4,7,1,5,9,6};
	auto it2 = find(numVect.begin(), numVect.end(), 100);
	if(it2 != numVect.end())
		cout << "Number found in the vector" << endl;
	else
		cout << "Didn't found Number in the vector" << endl;
	
	//Find all the numbers above 5
	globalNumToFind = 5;
	for_each(numVect.begin(), numVect.end(), findNum);
	for(auto num: globalResult)
		cout << num.Value() << " ";
	cout << endl;

	//Find all the numbers above 4
	
	vector<Number> result;
	NumberFinder finder{4, result};
	
	for_each(numVect.begin(), numVect.end(), finder);
	for(auto num: result)
		cout << num.Value() << "|";
	cout << endl;
	
	vector<Number> result2;
	int numToFind = 4;
	
	auto myLamda = 
				[numToFind, &result2](Number num)
				{if(num.Value()>numToFind) result2.push_back(num);};
	for_each(numVect.begin(), numVect.end(), myLamda);
				
	for(auto num: result2)
		cout << num.Value() << "*";
	cout << endl;
}
