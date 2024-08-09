#include <iostream>
using namespace std;

int main()
{
   int *int_ptr;

   //A pointer which has not been initialized to anything (not even NULL) is known as "wild pointer".

   cout << "Output of int_ptr before initialization = "<<  int_ptr << endl;             //<--gives address of the variable whose address is stored in the pointer
   cout << "Output of &int_ptr before initialization = "<< &int_ptr << endl;            //<--gives address of pointer.
   cout << "Output of *int_ptr before initialization = "<< *int_ptr << endl;            //<--gives out garbage value as ptr is not initilaize
   cout << endl;

   int_ptr = NULL;

   cout << "Output of int_ptr after initialization to NULL = "<<  int_ptr << endl;
   cout << "Output of &int_ptr after initialization to NULL = "<< &int_ptr << endl;
// cout << "Output of *int_ptr after initialization to NULL = "<< *int_ptr << endl;     //<--Code crashes due to dereferencing a null pointer
   cout << endl;

   string str  = "pratik";
   char * char_ptr = &str[0];

  cout << "Output of &char_ptr = "<< &char_ptr << endl<<endl;

  cout << "Output of char_ptr = "<<  char_ptr << endl;
  cout << "Output of (char_ptr+1) = "<< (char_ptr+1) << endl;
  cout << "Output of (char_ptr+2) = "<< (char_ptr+2) << endl<<endl;

  cout << "Output of *char_ptr = "<< *char_ptr << endl;
  cout << "Output of *(char_ptr+0) = "<< *(char_ptr+0) << endl;
  cout << "Output of *(char_ptr+1) = "<< *(char_ptr+1) << endl;
  cout << "Output of (char_ptr+sizeof(string)) = "<< (char_ptr+sizeof(char_ptr)) << endl<<endl;
  cout <<"-----------------------------------------------------------------------------------------------------"<<endl;


  //==========================================================================================================================================================//
  //
  //    const int* ptr;  ---> Pointer to Constant int type. You can modify ptr, can't modify *ptr.
  //    int * const ptr; ---> Constant Pointer to int type. You can't modify ptr, can modify *ptr.

  const int a = 10;
  const int* ptr = &a;

  cout << "ptr = " << ptr << endl;
  cout << "*ptr = " << *ptr <<endl;

  //*ptr = 5; // wrong
  ptr++;    // right

  cout << "ptr after increment = " << ptr << endl;
  cout << "*ptr after increment = " << *ptr <<endl<<endl;

  int b = 10;
  int *const ptrr = &b;

  cout << "ptrr = " << ptrr << endl;
  cout << "*ptrr = " << *ptrr <<endl;

  *ptrr = 5; // right
  //ptrr++;    // wrong

  cout << "ptrr after change = " << ptrr << endl;
  cout << "*ptrr after change = " << *ptrr <<endl<<endl;
  cout <<"-----------------------------------------------------------------------------------------------------"<<endl;
  //==========================================================================================================================================================//

return 0;
}
