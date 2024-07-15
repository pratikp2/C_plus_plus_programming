#include <iostream>
#include "number.h"
using namespace std;

Number getNum(int value){
	Number obj{value};
	return obj;
}
void main()
{
	//Number num1{10};
	//Number&& num1 = getNum(10);
	
	Number num2{20};
	num2 = Number{50};

}