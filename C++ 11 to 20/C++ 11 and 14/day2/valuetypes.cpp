#include <iostream>
using namespace std;
int number = 10;

// void setNum(int num){
	// cout << __FUNCSIG__ << endl;
// }

// void setNum(int& num){
	// cout << __FUNCSIG__ << endl;
	// number = num;
// }
void setNum(int&& num){
	cout << __FUNCSIG__ << endl;
	number = num;
}

int getNum(){
	return 10;
}

int& getNumber(){
	return number;
}
void main()
{
	//int& refNum{10};		//Error:
	int&& refNum{10};
	
	int num{10};
	
	int& refNum2{num};
	//int&& rrefNum2{num};	//Error: cannot convert from 'int' to 'int &&'
	
	//int& refNum3{num++};	//Error: cannot convert from 'int' to 'int &'
	int&& rrefNum3{num++};
	
	int& refNum4{++num};
	//int&& rfefNum4{++num};
	
	//setNum(num);
	setNum(10);
	setNum(static_cast<int&&>(num));
	
	//int& refNum5 = getNum();	//Error
	int&& rrefNum5 = getNum();
	
	int& refNum6 = getNumber();
	//int&& rrefNum6 = getNumber();	//Error
}