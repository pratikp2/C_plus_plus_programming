#include <iostream>
using namespace std;

void printNum(int num)
{
	cout << num << endl;
}
void printNum(int* num){
	if(num != nullptr)
		cout << *num << endl;
	else
		cout << "Illegal value" << endl;
}

void printNum(double* num){
	if(num != nullptr)
		cout << *num << endl;
	else
		cout << "Illegal value" << endl;
}

void printNum(nullptr_t){
	cout << __FUNCSIG__ << endl;
	cout << "Illegal value" << endl;
}

void main()
{
	int num = 10;
	printNum(&num);
	
	//printNum(NULL);
	printNum(nullptr);		//C++11 literal type
}