#include <iostream>
using namespace std;

template <typename T>
void byteSwap(T& num){
	if(is_integral<T>::value && sizeof(T) > 1)
	{
		unsigned char* bytes = reinterpret_cast<unsigned char*>(&num);
		for(int i = 0; i < sizeof(num); i +=2){
			unsigned char byte = bytes[i];
			bytes[i] = bytes[i+1];
			bytes[i+1] = byte;
		}
		cout << "After swaping: " << num << endl;
	}
	else
		cout << "Illegal value to swap!!" << endl;
}


void main()
{
	int num = 20;
	byteSwap(num);
	
	short num2 = 20;
	byteSwap(num2);
	
	double num3{20.2};
	byteSwap(num3);

	float num4{20.2f};
	byteSwap(num4);
	
	char ch = 10;
	byteSwap(ch);
}





