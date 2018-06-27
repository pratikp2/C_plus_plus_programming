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

