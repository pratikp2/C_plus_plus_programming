#include <iostream>
using namespace std;

[[deprecated("print function is deprecated. Please use printFormatted instead")]]
void print(int num){
	cout << num << endl;
}

void printFormatted(int num){
	cout << "***" << num << "***" << endl;
}

[[noreturn]]
void preCleanup(){
	cout << __FUNCSIG__ << endl;
	abort();
}
void postCleanup(){
	cout << __FUNCSIG__ << endl;
}
bool terminate(bool bForceful){
	if(bForceful){
		preCleanup();
		return true;
	}
	else
	{
		return false;
	}
}

void main()
{
	print(10);
}