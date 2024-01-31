#include <iostream>
using namespace std;

template <typename T>
struct isSwapable{
	static const bool value = false;
};
template <>
struct isSwapable<int>{
	static const bool value = true;
};
template <>
struct isSwapable<short>{
	static const bool value = true;
};
template <>
struct isSwapable<long>{
	static const bool value = true;
};
template <>
struct isSwapable<long long>{
	static const bool value = true;
};
template <>
struct isSwapable<unsigned int>{
	static const bool value = true;
};


template <typename T>
void byteSwap(T& num){
	if(isSwapable<T>::value)
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

// template <>
// void byteSwap(double& num){
	// cout << "Illegal value to swap" << endl;
// }

// template <>
// void byteSwap(float& num){
	// cout << "Illegal value to swap" << endl;
// }

// template <>
// void byteSwap(char& num){
	// cout << "Illegal value to swap" << endl;
// }


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





