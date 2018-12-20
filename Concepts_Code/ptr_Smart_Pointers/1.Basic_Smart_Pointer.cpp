/** ******************************************************************************************************
 *
 *  Prefixing the explicit keyword to the constructor prevents the compiler from using that constructor
 *  for implicit conversions.(Core purpose to restrict the use of constructor as a Conversion Constructor)
 *
 *  Smart pointer is a wrapper class over a pointer with operator like * and -> overloaded.
 *
 *  The objects of smart pointer class look like pointer, but can do many things that a normal pointer
 *  can’t like automatic destruction
 *
 *********************************************************************************************************/
#include <iostream>
using namespace std;


class Smart_ptr
{
    int * ptr;

public:
    explicit Smart_ptr(int *p = NULL)
    {
        this -> ptr = p;
        cout << "Smart Pointer Is Instantiated" << endl;
    }

    ~Smart_ptr()
    {
        delete (ptr);
        cout << "Smart Pointer Is destroyed" << endl;
    }

    int &operator *() { return *ptr; }
};

int main()
{
    Smart_ptr Smrtptr(new int());
    *Smrtptr = 20;
    cout << "Value Stored by the smart pointer is : " << *Smrtptr <<endl;

    return 0;
}

