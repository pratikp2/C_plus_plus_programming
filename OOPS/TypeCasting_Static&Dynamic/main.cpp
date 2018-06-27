/**
@ http://www.bogotobogo.com/cplusplus/dynamic_cast.php
*/


#include<dynamiccast.h>



int main()
{
//    Base b;
//    Derived d;

//        Base *pb = dynamic_cast<Base*>(&d);      	// #1
//        Derived *pd = dynamic_cast<Derived*>(&b); 	// #2

//                                    //1.The #1 is ok because dynamic_cast is always successful
//                                    //when we cast a class to one of its base classes.

//                                    //2.Code at #2 Compailes Successfully.
//                                    //But at runtime, the #2 cast fails and produces null pointer.

//                                    //if a virtual function is not present in Base class the dynamic
//                                    //cast in case #2 will fail as class Base in not polymorhic
//                                    // It wii throw a compailation error as
//                                    //"error C2683: 'dynamic_cast' : 'Base' is not a polymorphic type."
//                                    //It's because base-to-derived conversions are not allowed with
//                                    //dynamic_cast unless the base class is polymorphic.

//   Base *pDerived = new Derived;
//   Base *pBase    = new Base;
//   Derived *pc;

//         *pc = dynamic_cast<Derived>(&pDerived); // #3
//         *pc = dynamic_cast<Base>(&pBase);       // #4

//                                    //type Derived. But only the #3 is successful.
//                                    // #4 similar to case 2

//                                    //Even though pBDerived and pBBase are pointers of type Base*,
//                                    //pBDerived points to an object of type Derived, while pBBase points
//                                    //to an object of type Base. Thus, when their respective type-castings
//                                    //are performed using dynamic_cast, pBDerived is pointing to a full
//                                    //object of class Derived, whereas pBBase is pointing to an object
//                                    //of class Base, which is an incomplete object of class Derived.

//                                    //dynamic_cast<TYPE *>(ptr)
//                                    //converts the pointer ptr to a pointer of type Type* if the pointer-to
//                                    //object (*ptr) is of type TYPE or else derived directly or indirectly
//                                    //from type TYPE. Otherwise, the expression evaluates to 0, the null
//                                    //pointer.


    return 0;
}

