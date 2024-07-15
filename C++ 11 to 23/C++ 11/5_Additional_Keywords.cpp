#include <iostream>
using namespace std;

class Explore final
{
}; // <--

class Base
{
public:
    virtual void Function1() {}
    Base(const Base &objBase) = delete {} // <--
    Base *ptrBase = nullptr;              // <--
};

class Derived : public Base
{
public:
    Derived() default {}         // <--
    void Function1() override {} // <--
};

int main()
{
    return 0;
}

// final    : If keyword "final" is mentioned in front of a class, then Compiler will not allow any other class
//            to inherit from that Class .

// delete   : The compiler prohibits the usage of a deleted function.

// nullptr  : nullptr is a keyword that can be used at all places where NULL is expected. Like NULL, nullptr is
//            implicitly convertible and comparable to any pointer type. Unlike NULL, it is not implicitly
//            convertible or comparable to integral types.

// default  : If no user-declared constructors of any kind are provided for a class type (struct, class, or union),
//            the compiler will always declare a default constructor as an inline public member of its class.

// override : 1. Ensures there is a method with the same name in the parent class.
//            2. The method in the parent class is declared as “virtual” which means it was intended to be rewritten.
//            3. The method in the parent class has the same signature as the method in the subclass.
