#include<iostream>
using namespace std;

class Explore
{
    int val1;
    const int val2;
    const int val3 = 30;                // must use -std=c++11 flag to work.
public:
    Explore(): val1(10),val2(20){}      // In Previous version Initilizer Lisr is used to initiliaze const member parameter

    void Function1 () const             // Must be declared const at both times i,e. while prototyping and while defining.
    {
        cout << "Calling Function 1"<<endl;
    }
    void Function2 ()
    {
        cout << "Calling Function 2"<<endl;
    }
};

int main()
{
    const Explore ObjExplore1;
    Explore ObjExplore2;

    ObjExplore1.Function1();        // As obj is constant hence can call only const function so calling function 2 via
                                    // ObjExplore1 is not allowed
    ObjExplore2.Function1();        // Can call const as well as non comst function via non const object
    ObjExplore2.Function2();
    return 0;
}

// const member parameter has to br initiliaze by initilizer list. In C++ 11 it can be initiliaze in the
// class body itself

// The const property of an object goes into effect after the constructor finishes executing and ends before
// the class's destructor executes. So the constructor and destructor can modify the object, but other methods
// of the class can't. Only const methods can be called for a const object.

// The this pointer passed to a const method is a pointer to a const object. That means the pointer can not be
// used to modify the object's data members. Any attempt to change a data member of the object that called a
// const method will result in a syntax error, as will attempting to call a non-const method for that object.
