#include <iostream>
using namespace std;

void print(int&& num){
	cout << num;
}

void printWrapper(int&& num){
	print(std::forward<int>(num));		//Error: cannot convert argument 1 from 'int' to 'int &&'
}
void main()
{
	//print(10);
	printWrapper(10);
	int i = 0;
	//printWrapper(i);
}