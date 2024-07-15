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

//The performances are exactly the same as references are implemented internally as pointers. But still,
// you can keep some points in your mind to decide when to use what:  

//Use references: 
//In function parameters and return types.

//Use pointers: 
//If pointer arithmetic or passing a NULL pointer is needed. For example, for arrays (Note that accessing 
// an array is implemented using pointer arithmetic).

//To implement data structures like a linked list, a tree, etc. and their algorithms. This is so because,
// in order to point to different cells, we have to use the concept of pointers.

/*
Aspect	                    Pointer	                                                Reference
Declaration	                int* ptr	                                            int& ref
Initialization	            Can be initialized to nullptr or address of a variable	Must be initialized when declared and cannot be null
Reassignment	            Can be reassigned to point to different objects	        Cannot be reassigned after initialization
Dereferencing	            Explicit dereferencing using *	                        Automatically dereferenced
Nullability	                Can be nullptr	                                        Cannot be null
Memory Address	            Can store the memory address of a variable	            Acts as an alias to an existing variable
Pointer Arithmetic	        Supports pointer arithmetic (e.g., ptr++)	            Does not support pointer arithmetic
Use in Data Structures	    Used in implementing dynamic data structures	        Not typically used for dynamic data structures
Function Argument	        Useful for optional parameters and dynamic arrays	    Preferred for mandatory parameters
Memory Management	        Can manage dynamic memory allocation	                Cannot manage dynamic memory allocation
Syntax for Member Access	Uses -> for accessing members of a pointed-to object	Uses . for accessing members
Lifetime	                Lifetime can be controlled and changed	                Lifetime is tied to the object it references
Safety	                    Requires explicit checks for nullptr	                Generally safer as it cannot be null
*/
