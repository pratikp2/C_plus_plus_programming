#include <iostream>
using namespace std;


int main()
{
	int number = 0, reverse = 0;

	cout << "Please enter a number to reverse" << endl;
	cin >> number;
	
	for ( ;number != 0; )
	{
		reverse = reverse * 10;
		reverse = reverse + number%10;
		number = number/10;
		
		cout << endl << endl;
		cout << "Number 	: " << number << endl;
		cout << "Reverse 	: " << reverse << endl;
	}
	cout<< endl;
	
	return 0;
}
