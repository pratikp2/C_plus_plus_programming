/* **********************************************************************************************************************
 *
 *  Compile with C++ 11 flag    :   g++ main.cpp -std=c++11     // Keyword override
 *
** *********************************************************************************************************************/
#include<iostream>

class Interface
{
public:
    virtual void Fucntion() = 0;
};

void Interface::Fucntion()
{
    std::cout <<std::endl;
    std::cout << "Calling Pure Virtual Method" << std::endl <<std::endl;
}

class Parent
{
public:
    void function1(){std::cout << "Parent Class -- IN FUNCTION 1" << std::endl;}
    virtual void function2(){std::cout << "Patent Class -- IN FUNCTION 2" << std::endl;}
    virtual void function3(){std::cout << "Parent Class -- IN FUNCTION 3" << std::endl;}
    virtual void function4(){std::cout << "Parent Class -- IN FUNCTION 4" << std::endl<<std::endl;}
};

class Child : public Interface, public Parent
{
public:
    Child(){Interface::Fucntion();}
    void Fucntion()override {std::cout << "Overloaded from Interface" << std::endl;}

    void function1() {std::cout << "Child Class -- IN FUNCTION 1" << std::endl;}
    void function2() {std::cout << "Child Class -- IN FUNCTION 2" << std::endl;}
    void function4(int){std::cout << "Child Class -- IN FUNCTION 3" << std::endl;}
};

int main()
{
    Parent * ptr = new Child;

    ptr->function1();   // Early Binding
    ptr->function2();   // Late Binding
    ptr->function3();   // Late Binding
    ptr->function4();   // Late Binding

    // It's possible for a Pure virtual fuction to have Body. It can't be define inside class body
    // It has to be defined outside the class. And can be called via derived class using scope resolution
    // operator. e.g, Interface::Fucntion();

    // Function 1 will be called from Parent, because because in Parent function one is not virtual hence
    // it will be bind early and at early binding function gets called form pointer type i,e. Class Parent.

    // Function 2 will get called from Child, because because in Parent it is virtual hence it will undergo
    // through late binding. And at late binding function from a class will get called, whose address is hold
    // by pointer. e.g, Class child.

    // Function 3 will get called from Parent, because in parent it is virtual hence it will undergo through
    // late binding. But as Function3 functionality is not overriden in the Child Class vptr in V table will
    // point to function from class Parent.

    // Function 4 will get called from Parent, because in parent it is virtual hence it will undergo through
    // late binding. Child class contains function 4 but its argument signature is different. Hence its not
    // function overriding it's "Function Hiding". That is why vptr in V table will point to function4 from
    // class Parent.

    return 0;
}
