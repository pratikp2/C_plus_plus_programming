#include <iostream>
using namespace std;

int number = 0;
template <typename T>
void setNum(T&& val){		
	number = val;
}
void main()
{
	setNum(10);
	
	int num{10};
	setNum(num);
}