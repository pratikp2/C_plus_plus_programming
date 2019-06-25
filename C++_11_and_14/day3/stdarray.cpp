#include <iostream>
#include <array>
#include <exception>
using namespace std;

void processArray(array<int, 5> arr){
	for(int i = 0; i < arr.size(); i++){
		cout << arr[i] << "*";
		arr[i] = i;
	}
	cout << endl;
	//cout << arr[100000] << endl;
	cout << arr.at(100000) << endl;
}

auto getArray(){
	array<int, 5> arr{1,2,3,4,5};
	return arr;
}

void main(){
	array<int, 5> arr{0};
	for(auto val : arr)
		cout << val << "|";
	cout << endl;
	
	try{
		processArray(arr);
		for(auto val : arr)
			cout << val << "|";
		cout << endl;
	}catch(exception e){
		cout << "Exception catched: " << e.what() << endl;
	}
	auto arr2 = getArray();
	for(auto val : arr2)
		cout << val << "|";
	cout << endl;
}








