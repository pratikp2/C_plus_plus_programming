#include <iostream>
#include <vector>
using namespace std;

void main()
{
	int numArr[] = {1,2,3,4,5};
	
	//before c++11:
	for(int i = 0; i < 5; i++)
		cout << numArr[i] << " ";
	cout << endl;
	
	//better way: C++11
	for(int* ptr = begin(numArr); ptr != end(numArr); ptr++)
		cout << *ptr << "|";
	cout << endl;
	
	//best way: C++11
	for(int value : numArr)
		cout << value << "*";
	cout << endl;
	
	vector<int> numVect = {10,20,30,40,50};
	for(int value : numVect)
		cout << value << "|";
	cout << endl;
	
	for(int& value : numVect)
		value *= 10;
	
	for(auto value : numVect)
		cout << value << "|";
	cout << endl;
}





