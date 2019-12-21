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

template <class DataType>
class Smart_ptr
{
    DataType * ptr;

public:
    explicit Smart_ptr(DataType *p = NULL)
    {
        this -> ptr = p;
        cout << endl << "Smart Pointer Is Instantiated" << endl;
    }

    ~Smart_ptr()
    {
        delete (ptr);
        cout << "Smart Pointer Is destroyed" << endl << endl;
    }

    DataType & operator *()
    {
        cout << "Overloading *" << endl;
        return *ptr;
    }

    DataType * operator ->()
    {
        cout << "Overloading ->" << endl;
        return ptr;
    }
};

int main()
{
    Smart_ptr<int> Smrtptr(new int);
    Smart_ptr<double> Smrtdbptr(new double);

    *Smrtptr = 20;
    *Smrtdbptr = 40;
    cout << "Value Stored by the smart pointer is : " << *Smrtptr <<endl;
    cout << "Value Stored by the smart pointer is : " << *Smrtdbptr <<endl;


    return 0;
}

