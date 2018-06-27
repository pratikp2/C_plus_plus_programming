#include <iostream>
using namespace std;

int main()
{
    void * ptr;
    int a = 5;
    float b = 5.5;
    ptr = NULL;

    //cout <<"Value for *ptr                        : "<<*ptr<<endl;    //Telling compiler to dereference a void* but since it is a void * compiler has no idea
                                                                        //to what the memory at ptr is meant to look like.Is it a int or float or char memory ?
    ptr = &a;
    cout <<"Value for *ptr after int assignment    : "<<(*(int*)ptr)<<endl;
    ptr = &b;
    cout <<"Value for *ptr after float assignment  : "<<(*(float*)ptr)<<endl<<endl;

    /**
     *  A void pointer is a pointer that can point to any type of object, but does not know what type of object it points to.
     *  A void pointer must be explicitly cast into another type of pointer to be dereferenced. A null pointer is a pointer
     *  that does not point to an address. A void pointer can be a null pointer
    */

    return 0;
}
