#include <iostream>
#include "customarray.h"
using namespace std;

void main()
{
	CustomArray<int, 2> arr = {1,2,3,4,5};
	arr.PushBack(6);
	arr.PushBack(7);
	arr.PushBack(8);
	arr.PushBack(9);
	arr.PushBack(10);
	for(auto value : arr)
		cout << value << "*";
	cout << endl;
	
	CustomArray<float, 10> arr2 = {10.2f,2.3f,3.2f,4.7f,5.8f};
	
	for(auto value : arr2)
		cout << value << "|";
	cout << endl;
}