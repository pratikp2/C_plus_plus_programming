#include <iostream>
#include <exception>
using namespace std;

void readFile()noexcept(false){
	cout << __FUNCSIG__ << endl;
	throw exception();
}

void readData()noexcept(noexcept(readFile())){
	cout << __FUNCSIG__ << endl;
	readFile();
}

void readStream(){
	cout << __FUNCSIG__ << endl;
}

void main()
{
	try{
		readData();
		readStream();
	}catch(exception e){
		cout << "Exception Catched!!" << endl;
	}
}