#include <iostream>
using namespace std;

void showNo(int & Number)        // Function 1 (with lvalue reference)
{
    cout << "The Passed No is " << Number << " with rvalue reference"<<endl;
}

void showNo(int && Number)       // Function 2 (with rvalue reference)
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


//  int a = 20;

//  For above instruction "a" is lvalue and "&a" is lvalue reference, whereas "20" is r value.
//  lvalue us variable value which yields address eg "&a", but on trying to get address of no "20"
//  compiler will throw an error, hence it is a rvalue.

//  hence "showNO(20)" will call "showNo(int && Number)" because 20 is rvalue reference.


//NOTE :
//compile with flag "g++ -std=c++11 main.cpp" to include "C++ 11" features,and make necessary
//changes to IDE compiler to compile "C++ 11" features.


