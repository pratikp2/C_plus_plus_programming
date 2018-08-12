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


// As Function 1 in Derived class is Defined with keywoed "override" one of the parent
// class of the Derived Class has to Override it or compiler will throw error.
// Make use of -std=c++11 flaf for compailation.
