/** ******************************************************************************************************
 *
 *      1. auto_ptr     :   auto_ptr<DataType> ptrName(new DataType)
 *      --It is based on exclusive ownership model i.e. two pointers of same type can’t point to the same
 *        resource at the same time.
 *      --The copy constructor and the assignment operator of auto_ptr do not actually copy the stored
 *        pointer instead they transfer it, leaving the first auto_ptr object empty.
 *      --This class template is deprecated as of C++11. unique_ptr is a new facility with a similar
 *        functionality, but with improved security.
 *
 *      2. unique_ptr   :   auto_ptr<DataType> ptrName(new DataType)
 *      --std::unique_ptr was developed in C++11 as a replacement for std::auto_ptr.
 *      --added features (deleters) and support for arrays.
 *      --since there can only be one unique_ptr to any resource, so any attempt to make a copy of
 *        unique_ptr will cause a compile time error.
 *
 *        unique_ptr<A> ptr1 (new A);
 *        unique_ptr<A> ptr2 = ptr1;        // Error: can't copy unique_ptr
 *
 *
 *********************************************************************************************************/
#include <iostream>
#include<memory>
using namespace std;

class SmartPointers
{

};

int main()
{
    //////////////////////////////////////////////////////////////////////////////////////////////////

    auto_ptr<SmartPointers> ptr(new SmartPointers);
    cout << "Address Of the First auto_ptr  :    " << ptr.get() << endl; // gives address of the pointer.

    auto_ptr<SmartPointers> ptr1(ptr);
    cout << "Address Of the Second auto_ptr :    " << ptr1.get() << endl;
    cout << "Address Of the First auto_ptr after second auto_ptr is created :    " << ptr.get() << endl;
    cout << endl<<endl;

    //////////////////////////////////////////////////////////////////////////////////////////////////

    unique_ptr<SmartPointers> ptr3(new SmartPointers);
    cout << "Address Of the First unique_ptr  :    " << ptr3.get() << endl; // gives address of the pointer.

    unique_ptr<SmartPointers> ptr4 = move(ptr3);
    cout << "Address Of the Second unique_ptr :    " << ptr4.get() << endl;
    cout << "Address Of the First unique_ptr after second unique_ptr is created :    " << ptr3.get() << endl;
    cout << endl<<endl;

    //////////////////////////////////////////////////////////////////////////////////////////////////


    //////////////////////////////////////////////////////////////////////////////////////////////////


    //////////////////////////////////////////////////////////////////////////////////////////////////

    return 0;

}
