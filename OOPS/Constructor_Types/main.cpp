# include <iostream>
using namespace std;

class CopyConstructor
{
    public :
        //int x,y;
        CopyConstructor();// Default Constructor

        CopyConstructor(int var);// Parameterized Constructor

        CopyConstructor(const CopyConstructor&);// Copy Constructor

        CopyConstructor& operator = (const CopyConstructor &obj);// Assignment Operator
};

CopyConstructor :: CopyConstructor()            // Default Constructor
{
    cout << "1.This is Default constructor given by the compiler" <<endl;
}

CopyConstructor :: CopyConstructor(int var)
{
    cout << "2.This is Parameterized constructor." << endl;
}

 CopyConstructor :: CopyConstructor(const CopyConstructor& obj)
 {
    cout << "3.This is Copy constructor." << endl;
 }

 CopyConstructor& CopyConstructor :: operator = (const CopyConstructor &obj)
    cout << "This is Assignment Operator" << endl;
 }
int main ()
{
    CopyConstructor obj1;
    CopyConstructor obj2(5);
    CopyConstructor obj3 = obj1;
    obj1 = obj2;
    return 0;
}

// when providing a parameterize constructor or copy constructor the make sure to provide definition for default
// constructor if object is being created using a default constructor (Code Line : CopyConstructor obj1).

// When passing object to the assignment operator by "pass by value" 1st copy constructor and then assignment
// operator will get called
