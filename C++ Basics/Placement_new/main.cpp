#include <iostream>
using namespace std;

int main()
{
    int * ptr1 = new int(10);
    cout << "Address Hold by 1st Pointer    :   "<< ptr1 << endl;
    cout << "Value Hold by 1st Pointer      :   "<< *ptr1 << endl << endl;


    int * ptr2 = new (ptr1) int(100);
    cout << "Address Hold by 2nd Pointer    :   "<< ptr2 << endl;
    cout << "Value Hold by 2nd Pointer      :   "<< *ptr2 << endl;
    cout << "Value Hold by 1st Pointer      :   "<< *ptr1 << endl << endl;

    int var = 20;
    cout << "Address of 1st Variable        :   "<< &var << endl;
    cout << "Address of the 1st variable    :   "<< var << endl << endl;

    int * ptr3 = new (&var) int(200);
    cout << "Address of 2nd Variable        :   "<< ptr3 << endl;
    cout << "Address of the 2nd variable    :   "<< *ptr3 << endl;
    cout << "Address of the 1st variable    :   "<< var << endl << endl;

    delete ptr1;
    //delete ptr3;

    cout << "Value Hold by 1st Pointer After deleting   :   "<< *ptr1 << endl;
    cout << "Value Hold by 2nd Pointer After deleting   :   "<< *ptr2 << endl << endl;

    return 0;

}

//Normal new allocates memory in heap and constructs objects tehre whereas using placement new, object construction can be done at known address.
//With normal new, it is not known that, at what address or memory location it’s pointing to, whereas the address or memory location that it’s 
// pointing is known while using placement new.
//The deallocation is done using delete operation when allocation is done by new but there is no placement delete, but if it is needed one can 
// write it with the help of destructor.

// We can not delete ptr3 because the memory allocated in the placement new is aloocated in the stack by the previous variable.
// Hence deleting ptr3 will give error.
