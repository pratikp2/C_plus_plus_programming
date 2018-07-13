/** **************************************** Prototypes **********************************************

*   Explicit Cast       :   new_type (expression)

*   Constant Cast       :   const_cast <new_type> (expression)

*   Reinterpret Cast    :   reinterpret_cast <new_type> (expression)

*   Dynamic Cast        :   dynamic_cast <new_type> (expression)

*****************************************************************************************************/
#include <iostream>
using namespace std;


class CastingHub
{
public :
    int a = 27;
    int var = 8;                // Declaration and Initialize has to to done at same time for constant types.
    const int *ptr = &var;

    CastingHub();
    void function1(int *ptr1){cout << "Value for the Pointer ptr is : " << *ptr << endl;}
    void function2() const
    {
        (const_cast <CastingHub*> (this) ) -> a = 20;
    }
}ObjCastingHub;

class Derived : public CastingHub
{
public:
    Derived();
};

class FreeCall
{

};

int main()
{
    int b = 10;
    float c = 20.10;
    b = c;
    cout << "Value for the variable B is : " << b << endl;      // Implicit typecasting :
                                                                // compiler automatically casts float into int
                                                                // and discards the fraction.
    //---------------------------------------------------------------------------------------------------------------//

    float d = 5.5;
    int e = 15;
    e = int(d) + e;
    cout << "Value for the variable E is : " << e << endl;      // Explicit typecasting :

    //---------------------------------------------------------------------------------------------------------------//

    // const_cast is used to cast away the constness of variables (pointers)
    // and vice versa() i,e. send non-const data to a function where const data is expected.

    int * ptr1 = const_cast <int*> (ObjCastingHub.ptr);
    ObjCastingHub.function1(ptr1);        // can not pass const type where non-const is expected

    // const cast can be use to change non const data inside a const function.

    ObjCastingHub.function2();        // function2 is const type function
    cout << "Value for the variable A is : " << ObjCastingHub.a << endl<<endl;

    //  It is undefined behavior to modify a value which is initially declared as const.
    //  It it fine to modify a value which is not initially declared as const

    //---------------------------------------------------------------------------------------------------------------//

    // Reinterpret Cast is used to convert one pointer of another pointer of any type.

    int *h = new int(36);
    char *ch = reinterpret_cast <char*> (h); // Value in h gets considered as ASCII value.

    cout << "Value for the Pointer h is : " << *h << endl;
    cout << "Value for the Pointer ch is : " << *ch << endl;
    cout << "Value for the h is : " << h << endl;
    cout << "Value for the ch is : " << ch << endl;

    // Reinterpret Cast also is used to convert integer types to pointer types and vice versa

    //---------------------------------------------------------------------------------------------------------------//

    // The most important thing to know is that static_cast is used to reverse implicit conversions.
    // static-cast is useful for compile time check for check.

    CastingHub * ObjCastinghub;
    Derived * ObjDerived;
    FreeCall * ObjFreeCall;

    //ObjDerived = static_cast <Derived> (ObjCastinghub);

    //---------------------------------------------------------------------------------------------------------------//

    // Used to perform runtime check
    // Makes sure that the pointer is pointing to the complete object.

    //---------------------------------------------------------------------------------------------------------------//
    return 0;
}

