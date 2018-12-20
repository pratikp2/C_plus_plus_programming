#include <iostream>
using namespace std;

template <class Datatype>

class shared_ptr
{
private :
    static Datatype * ptr;
    static int ReferenceCount;

public:
    explicit shared_ptr(Datatype *p = NULL)
    {
        cout << "Constructor called" << endl;
        ReferenceCount = ReferenceCount + 1;
        this -> ptr = p;
    }

    explicit shared_ptr(shared_ptr & obj)
    {
        cout << "Constructor called" << endl;
        ReferenceCount = ReferenceCount + 1;
    }

    ~shared_ptr()
    {
        ReferenceCount = ReferenceCount - 1;
        if (!ReferenceCount){ delete ptr; }
    }

    Datatype & operator *(){ return * ptr; }

    Datatype * operator ->() { return ptr; }

    void operator = (Datatype val) {*ptr = val;}

    Datatype & get() { return * ptr; }

    int use_count() { return ReferenceCount; }

    void reset( Datatype * p) { p = NULL; }
};

template <typename Datatype>
Datatype * shared_ptr <Datatype>:: ptr = NULL;

template <typename Datatype>
int shared_ptr <Datatype> :: ReferenceCount = 0;

int main()
{
    shared_ptr<int> ptr1(new int);
    cout << *ptr1 << endl;
    cout << ptr1.get() << endl;
    cout << ptr1.use_count() << endl << endl;

    shared_ptr<int> ptr2(ptr1);
    cout << *ptr2 << endl;
    cout << ptr2.get() << endl;
    cout << ptr2.use_count() << endl;

    return 0;
}
