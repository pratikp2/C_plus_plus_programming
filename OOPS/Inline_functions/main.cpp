#include <iostream>

using namespace std;

inline int sq(int x)
{
    return x*x;
}

int main()
{
    int a=8;
    int b=7;

    int c=sq(a);
    int d=sq(10+b);

    cout<<c<<"     "<<d<<endl;
    return 0;
}

//Inline function is a function that is expanded in line when it is called. When the inline function
//is called whole code of the inline function gets inserted or substituted at the point of inline function
//call. This substitution is performed by the C++ compiler at compile time.


// As stated above all the line in inline functions are replaced in actual code at compile time, there is no scope
// or loop binding the lines of code. This is the reason that inline functions cannot be called recursively. Beacause
// at the time of stack unwinding there is no successive loop or scope to jump for program control.

/*
Remember, inlining is only a request to the compiler, not a command. Compiler can ignore the request for inlining.
Compiler may not perform inlining in such circumstances like:
1) If a function contains a loop. (for, while, do-while)
2) If a function contains static variables.
3) If a function is recursive.
4) If a function return type is other than void, and the return statement doesn’t exist in function body.
5) If a function contains switch or goto statement.
*/
