/**************************************************************************************************************
 * 
 * static_cast is used for conversions between compatible types, such as casting from an integer to a float,
 *  or between pointer types within an inheritance hierarchy where the cast is known to be safe.
 * 
 * dynamic_cast is used for safe downcasting and can also be used for cross-casting (casting across a hierarchy).
 * It performs runtime type checking and returns nullptr if the cast is invalid.
 * 
 **************************************************************************************************************/

#include <iostream>

class Base {
public:
    virtual void show() {
        std::cout << "Base class show() method" << std::endl;
    }

    virtual ~Base() = default;  // Polymorphic class with a virtual destructor
};

class Derived : public Base {
public:
    void show() override {
        std::cout << "Derived class show() method" << std::endl;
    }
};

class AnotherDerived : public Base {
public:
    void display() {
        std::cout << "AnotherDerived class display() method" << std::endl;
    }
};

int main() {
    //////////////////////////////////////////////////////////////////////////////////////////////////////////


    Base* basePtr = new Derived; // Upcast (implicitly allowed)
    basePtr->show();             // Calls Derived's show()

    // Downcast using static_cast (safe because we know basePtr is actually pointing to a Derived object)
    Derived* derivedPtr = static_cast<Derived*>(basePtr);
    derivedPtr->show();          // Calls Derived's show()

    delete basePtr;

    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    Base* basePtr = new Derived;

    // Safe downcast using dynamic_cast
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
    if (derivedPtr) {
        derivedPtr->show();  // Valid downcast, so this block is executed
    } else {
        std::cout << "Invalid cast to Derived" << std::endl;
    }

    // Attempt an invalid downcast
    AnotherDerived* anotherDerivedPtr = dynamic_cast<AnotherDerived*>(basePtr);
    if (anotherDerivedPtr) {
        anotherDerivedPtr->display();
    } else {
        std::cout << "Invalid cast to AnotherDerived" << std::endl;
    }

    delete basePtr;
    return 0;

    //////////////////////////////////////////////////////////////////////////////////////////////////////////
}

// Static Cast
// A Base class with a virtual method show().
// A Derived class that overrides the show() method.
// basePtr is a pointer to Base, but it actually points to a Derived object (upcasts is implicitly allowed).
// Using static_cast, we downcast basePtr to Derived* and call the show() method on derivedPtr.


// Dynamic Cast
// A Base class with a virtual destructor to make it polymorphic.
// Derived and AnotherDerived classes inherit from Base.
// basePtr is a pointer to Base, actually pointing to a Derived object.
// dynamic_cast is used to safely downcast basePtr to Derived* and check if the cast is valid.
// An invalid downcast to AnotherDerived* is attempted, and dynamic_cast returns nullptr if the cast is not valid,
//      allowing us to handle the error gracefully.