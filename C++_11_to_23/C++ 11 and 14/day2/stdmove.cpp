#include <iostream>
#include "customarray.h"
#include "number.h"
#include <vector>
using namespace std;

template<typename T>
void setNum(T&&){
	
}

void setNum(int&&){
	
}

//void setNum(int&&&)
void setNum(int&)  //after applying reference collapsing rule
{
	//fdfd
}

void main()
{
	setNum(10);
	int i = 10;
	setNum(i);

	CustomArray<Number, 1> numArray;
	// numArray.PushBack(1);
	// numArray.PushBack(2);
	// numArray.PushBack(3);
	
	int counter = 0;
	Number obj{10};
	while(counter++ < 100)
		numArray.PushBack(obj);
	

	// vector<Number> vectNum;
	// int counter = 0;
	// while(counter++ < 100)
		// vectNum.push_back(counter);
	
	 cout << "Number of Allocation: " << Number::__Count() << endl;

	//getFun(Number(10));
}