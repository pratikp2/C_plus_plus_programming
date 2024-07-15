#include <iostream>
#include <string>
using namespace std;

template <typename T>
class SmartPointer{
public:
	SmartPointer(T* p):ptr{p}{cout << "Smart Pointer for " << typeid(ptr).name() << endl;}
	~SmartPointer(){
		cout << "Deleting smart pointer: " << typeid(ptr).name() << endl;
		delete ptr; 
	}

	T& operator*(){return *ptr;}
	T* operator->(){return ptr;}
private:
	T* ptr;
};

void main(){
	SmartPointer<int> sp1{new int(10)};
	cout<< "Int Data: " << *sp1 << endl;
	{
		SmartPointer<string> sp2{new string("This is last session of our training")};
		cout << "Length of string: " << sp2->length() << endl;
	}
	
	cout << "Enter any char to exit..." << endl;
	getchar();
	
}
