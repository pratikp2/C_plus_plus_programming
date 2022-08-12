#include<iostream>
using namespace std; 

int main(int argc, char** argv)
{
    long long int a = 1'23'456;
    long long int b = 12'34'56;
    long long int c = 123'456;

    // Print all the value
    cout << "a:" << a << endl;
    cout << "b:" << b << endl;
    cout << "c:" << c << endl;

	return 0;
}


// 1000 is readable but what if more zeros are added to it, let’s say 1000000, now it becomes a little difficult to read, and what will happen if more zeros are added to it.
// In real life, commas(, ) are added to the number.For Example : 10, 00, 000. Now it is easy to read, that is ten lakhs.