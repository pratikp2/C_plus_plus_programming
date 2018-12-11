# include <iostream>
using namespace std;

class Base
{
public :
    virtual void Function1(){}
};

class Derived : public Base
{
public :
    void Function1() override
    {

    }
};

int main()
{
    return 0;
}


// As Function 1 in Derived class is Defined with keyword "override" one of the parent
// class of the Derived Class has to Override it or compiler will throw error.

// In short, it serves the following functions. It helps to check if :
//  1. There is a method with the same name in the parent class.
//  2. The method in the parent class is declared as “virtual” which means it was intended to be rewritten.
//  3. The method in the parent class has the same signature as the method in the subclass.

// Make use of -std=c++11 flag for compailation.
