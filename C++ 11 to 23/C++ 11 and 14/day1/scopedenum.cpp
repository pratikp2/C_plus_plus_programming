#include <iostream>
using namespace std;

enum class color:char{black, brown, blue, green};
enum signal{red, green, orange};

void main()
{
	color eyes = color::green;
	
	int currSig = red;
	int currEye = (int)color::blue;
	
	cout << typeid(color).name() << endl;
	cout << typeid(underlying_type<color>::type).name() << endl;
	
}