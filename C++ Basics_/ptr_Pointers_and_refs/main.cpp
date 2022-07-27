#include <iostream>
using namespace std;

int main()
{

    // Reference is the second name or alias of an existing variable.

    int c = 10;
    int &ref = c;        // "ref" is nothing but an alias for c with same address.

    cout << "Value for &c        = "<<&c<<endl;
    cout << "Value for c         = "<<c<<endl;
    cout << "Value for &ref      = "<<&ref<<endl;
    cout << "Value for ref       = "<<ref<<endl;


    int *int_ptr;
    int_ptr = &c;

    cout << "Value for int_ptr   = "<<int_ptr<<endl;
    cout << "Value for *int_ptr  = "<<*int_ptr<<endl<<endl;

    cout << "Hence &c = &ref = int_ptr"<<endl;
    cout << "And   c  = ref  = *int_ptr"<<endl<<endl;

    cout << "Reference (&ref) is nothing is a constant pointer (int_ptr) to a value"<<endl<<endl;

    return 0;
}

// Reference can not be inilized to NULL.

//The performances are exactly the same as references are implemented internally as pointers. But still, you can keep some points in
//your mind to decide when to use what:  

//Use references: 
//In function parameters and return types.

//Use pointers: 
//If pointer arithmetic or passing a NULL pointer is needed. For example, for arrays (Note that accessing an array is implemented 
//using pointer arithmetic).
//To implement data structures like a linked list, a tree, etc. and their algorithms. This is so because, in order to point to
//different cells, we have to use the concept of pointers.