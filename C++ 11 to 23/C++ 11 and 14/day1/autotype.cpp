#include <iostream>
#include <string>
#include <list>
using namespace std;

int number;
void setNumber(auto num){
	number = num;
}

auto getNumber(){
	return number;
}

void main()
{
	auto num {10};
	cout << typeid(num).name() << endl;
	
	auto& refNum{num};
	auto* ptrNum{&num};
	cout << typeid(ptrNum).name() << endl;
	
	auto str = "Welcome to C++11n14";
	cout << typeid(str).name() << endl;
	
	auto str2 = "Welcome to C++11n14"s;
	cout << typeid(str2).name() << endl;
	
	auto arr = {1,2,3,4,5};
	cout << typeid(arr).name() << endl;
	
	auto arr2 = list<string>{"s1", "s2"};
	
	setNumber(10);
	
	//auto num2;
}