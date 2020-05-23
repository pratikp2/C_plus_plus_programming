/** ***********************************************************************************************************
 *
 *  # Use double pointer when you want to preserve (OR retain change in) the Memory-Allocation or Assignment
 *    even outside of a function call.
 *
 * #  The "pointer to pointer" idiom dates back to C, where it was necessary. C did not have references.
 *
 **************************************************************************************************************/
#include <iostream>
#include <pthread.h>
using namespace std;

void Pass_Single_Ptr(int * x, int * z)
{
    x = z;
    cout << "Value of 'A' in function Pass_Single_Ptr after performing A = C : "<< x <<endl;
}

void Pass_Double_Ptr(int ** x, int * z)
{
    *x = z;
    cout << "Value of 'Dptr' in function Pass_Double_Ptr after performing *Dptr = C : "<< x <<endl;
}

int main()
{

    int c = 1;
    int d = 2;
    int e = 3;
    int * a = &c;
    int * b = &d;
    int * f = &e;
    int ** pp = &a;  // pointer to pointer 'a'

    cout << ""<<endl;
    cout << "Address stored in Pointer variable A is            : "<<a<<endl;
    cout << "Address stored in Pointer variable B is            : "<<b<<endl;
    cout << "Address stored in Pointer variable C is            : "<<f<<endl;
    cout << "Address stored in Double Pointer variable Dptr is  : "<<pp<<endl<<endl;


    cout << "As A is not constant Pointer it's value can be changes"<<endl;
    cout << "Hence Performing A = B" << endl<<endl;

    a = b;

    cout << "Address stored in Pointer variable A afer Change : "<<a<<endl;
    cout << "Address stored in Pointer variable B             : "<<b<<endl;
    cout << "Both Values are Same"<<endl<<endl;

    cout << "Now on Passing pointer variable in function to changes its value" <<endl;
    cout << "Pass_Single_Ptr(A, C) and performing A = C in Function"<<endl<<endl;

    Pass_Single_Ptr(a, f);
    cout << "Value of 'A' outside function Pass_Single_Ptr after performing A = C : "<< a <<endl;
    cout << "Value of the pointer variable is still same due to Pass By Value mechanism"<<endl<<endl;

    cout << "Now on Passing Double pointer variable in function to changes its value" <<endl;
    cout << "Pass_Double_Ptr(Dptr, C) and performing *Dptr = C in Function"<<endl<<endl;

    Pass_Double_Ptr(pp, f);
    cout << "Value of 'Dptr' outside function Pass_Double_Ptr after performing *Dptr = C : "<< pp <<endl;
    cout << "Value of the Double pointer variable is changed even if it used Pass By Value mechanism"<<endl<<endl;

    return 0;
}



/** *************************************************************************************************************************************
 *  #   When Passing pointers to a function(Pass_Single_Ptr) and copying one into another will lead to changing the address in the changed
 *      pointer whose scope will be only limited to the scope of funtion. Hence value outside the function will remain un changed due to
 *      simple pass by value mechanism.
****************************************************************************************************************************************/
