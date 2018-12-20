# include <iostream>
using namespace std;

class Base
{
public :
    void Rand_Function(){cout << " This is Random Function from Base" << endl;}
};

class Derived_One : public virtual Base
{
public:
    void Rand_Function(){cout << " This is Random Function from Derived_One" << endl;}
};

class Derived_Two : public virtual Base
{
public :
    void Rand_Function(){cout << " This is Random Function from Derived_Two" << endl;}
};

class Derived_Three : public Derived_Two, public Derived_One
{
public:
    void Rand_Function(){cout << " This is Random Function from Derived_Three" << endl;}
};

int main()
{
    Derived_Three ObjDerivedThree;

    ObjDerivedThree.Base::Rand_Function();
    ObjDerivedThree.Derived_One::Rand_Function();
    ObjDerivedThree.Derived_Two::Rand_Function();
    ObjDerivedThree.Derived_Three::Rand_Function();     // OR     ObjDerivedThree.Rand_Function();

    return 0;
}

// Note : Diamond problem and error due to ambiguity are two different things.

// Diamond Problem : Consider above example with Multiple Inheritance.
//      1. There is a "Base Class".
//      2. Classes "Derived_One" and "Derived_Two" are derived from "Base" Class
//      3. And "Derived_Three" Inherites from claseses Derived_One and Derived_Two ultimately deriving from Base Class.
//      4. Classes "Derived_One" and "Derived_Two" has overriden the method Random_Function from the Base CLass.

// Diamond problem will give ambiguity error only when below conditions are satisfied.
//      1. Definations from the Base class has been included twice in the "Derived_Three" Class via Derived_One and Derived_Two.
//      2. The defination which is included twice shoulden't be overriden in the "Derived_Three" Class.
//      3. And defination included twice should get called via object of the class "Derived_Three"

// To resolve diamond problem virtual inheritance is used, i,e. when inheriting from the base class make use of virtual keyword.
// Due to this the definations from the base class will be copied once in the "Derived_Three" Class and ambiguities due to Diamond
// problem will be gone.

// In above example if Derived_Three class do not overrides the Rand_Function(), and Rand_Function() is getting called via the
// object of the Drived_Three, ambiguity error will still be present. This happens because virtual keyword removed the ambiguity
// due to two definations of a function in the base class but Derived_Three Class still has definations from Derived_One and
// Derived_Two Class for the same function.

// To resolve this issue scope resolution operator should be used, It allows prgrammer to decide which class's functionality
// should get called.
