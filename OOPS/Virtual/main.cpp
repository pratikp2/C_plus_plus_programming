#include<iostream>

class Interface
{
public:
    virtual void fucntion1() = 0;
    virtual void fucntion2() = 0;
};

void Interface::fucntion1()
{
     std::cout << "INTERFACE -- IN FUNCTION 1" << std::endl;
}

class Abstract
{

};

class DummyClass1 : public Interface
{
public:
    void fucntion1()
    {
        Interface::fucntion1();
        std::cout << "DummyClass1 -- IN FUNCTION 1" << std::endl;
    }
};

class DummyClass2 : public Interface
{

};

int main()
{
    Interface * ptr = new DummyClass1;
    ptr->fucntion1();
    return 0;
}
