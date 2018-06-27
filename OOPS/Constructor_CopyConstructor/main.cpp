# include <iostream>

using namespace std;

class CopyConstructor
{
    public :
        //int x,y;
        CopyConstructor(){};
        CopyConstructor (const CopyConstructor&);
        CopyConstructor& operator = (const CopyConstructor &obj);
};

 CopyConstructor :: CopyConstructor(const CopyConstructor& obj)
 {
    cout << "Copy Constructor Called" << endl;
 }

 CopyConstructor& CopyConstructor :: operator = (const CopyConstructor &obj)
 {
    cout << "Assignment Operator Called" << endl;
 }
int main ()
{
    CopyConstructor obj1;
    CopyConstructor obj2; //= obj1;

    obj1 = obj2;
    return 0;
}

// when providing a parameterize constructor or copy constructor the make sure to provide definition for default
// constructor if object is being created using a default constructor (Code Line : CopyConstructor obj1).

// When passing object to the assignment operator by "pass by value" 1st copy constructor and then assignment
// operator will get called
