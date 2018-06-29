#include <iostream>
using namespace std;

void showNo(int & Number)        // Function 1
{
    cout << "The Passed No is " << Number << " with rvalue reference"<<endl;
}


void showNo(int && Number)       // Function 2
{
   cout << "The Passed No is " << Number << " with lvalue reference"<<endl;
}

int main()
{
    int a = 10;
    showNo(a);      // This will call Function 1

    showNo(20);     // This Will caLL Function 2

    int &&b = 20;       // To Initialize rvalue reference.
    return 0;
}

    //&c is lvalue reference and 10 is lvalue whicih can be addressed by (int &&c).
    //rvalue reference yields a address whereas lvalue don't yield a address (eg. &10 will throw a compiler error)

    //NOTE :
    //compile with flag "g++ -std=c++11 main.cpp" to include "c++ 11" features,and make necessary
    //changes to IDE compiler to compile cpp 11 features.


