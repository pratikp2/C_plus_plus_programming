#include <iostream>
using namespace std;


class Constructor_Type
{
   public :
        Constructor_Type()
        {
            cout << "1.This is Default constructor given by the compiler" << endl;
        }

        Constructor_Type(int a)
        {
            cout << a <<".This is Parameterized Constructor"<< endl;
        }
};

int main()
{
    Constructor_Type Default_Construcrot;
    Constructor_Type Parameterized_Constructor(2);
    return 0;
}

// when providing a parameterize constructor or copy constructor the make sure to provide definition for default
// constructor if object is being created using a default constructor (Code Line : Constructor_Type Default_Construcrot).
