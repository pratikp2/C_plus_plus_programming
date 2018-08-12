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
 *      3. shared_ptr   :   shared_ptr<DataType> ptrName(new DataType)
 *      -- It is a reference counting ownership model i.e. it maintains the reference count of its
 *         contained pointer in cooperation with all copies of the shared_ptr.
 *      -- Reference Counting: It is a technique of storing the number of references, pointers or handles
 *         to a resource such as an object, block of memory, disk space or other resources.
 *      -- An object referenced by the contained raw pointer will not be destroyed until reference count
 *         is greater than zero i.e. until all copies of shared_ptr have been deleted.
 *
 *
 *      4. weak_ptr     :    weak_ptr<DataType> ptrName(new DataType)
 *      -- A weak_ptr is created as a copy of shared_ptr. It provides access to an object that is owned
 *         by one or more shared_ptr instances, but does not participate in reference counting.
 *      -- Cyclic Dependency (Problems with shared_ptr): Let’s consider a scenario where we have two
 *         classes A and B, both have pointers to other classes. So, it’s always be like A is pointing
 *         to B and B is pointing to A. Hence, use_count will never reach zero and they never get deleted.
 *      -- This is the reason we use weak pointers(weak_ptr) as they are not reference counted. So, the
 *         class in which weak_ptr is declared doesn’t have strong hold of it i.e. the ownership isn’t
 *         shared, but they can have access to these objects.
 *
 *********************************************************************************************************/

#include <iostream>
#include<memory>
using namespace std;

class AliasDataType
{

};

class WeakPointer_Working
{
    // shared_ptr<WeakPointer_Working> m_ptr;       Creates problem of Cyclic Reference.
    weak_ptr<WeakPointer_Working> m_ptr;        // as same as WeakPointer_Work * m_ptr
    string m_name;

    public :
    WeakPointer_Working(string name) {cout << "Class " << name <<" is created."<<endl; m_name = name;}
    ~WeakPointer_Working() {cout << "Class " << m_name <<" is destroyed."<<endl;}
    void linkToObject(shared_ptr<WeakPointer_Working> ptr){m_ptr = ptr;}
    void showLink() { if(! m_ptr.expired()) cout << "Calling Object is linked with " << m_ptr.lock() -> m_name << endl; }
};

// "lock" functions creates a shared pointer out of calling weak pointer. Reason (1) It checks that
// if weak pointer is pointing to a valid object. (2) And ensures that object won't get deleted
// while we are accesing any thing from the weak pointer. If weak pointer is empty pointer then
// lock funtion thrrows an exception. "expired" functions gives true if object has been deleted.

int main()
{
    //////////////////////////////////////////////////////////////////////////////////////////////////

    auto_ptr<AliasDataType> ptr(new AliasDataType);
    cout << "Address Of the First auto_ptr  :    " << ptr.get() << endl; // gives address of the pointer.

    auto_ptr<AliasDataType> ptr1(ptr);
    cout << "Address Of the Second auto_ptr :    " << ptr1.get() << endl;
    cout << "Address Of the First auto_ptr after second auto_ptr is created :    " << ptr.get() << endl;
    cout << endl<<endl;

    //////////////////////////////////////////////////////////////////////////////////////////////////

    unique_ptr<AliasDataType> ptr3(new AliasDataType);
    cout << "Address Of the First unique_ptr  :    " << ptr3.get() << endl; // gives address of the pointer.

    unique_ptr<AliasDataType> ptr4 = move(ptr3);
    cout << "Address Of the Second unique_ptr :    " << ptr4.get() << endl;
    cout << "Address Of the First unique_ptr after second unique_ptr is created :    " << ptr3.get() << endl;
    cout << endl<<endl;

    //////////////////////////////////////////////////////////////////////////////////////////////////

    shared_ptr<AliasDataType> ptr5(new AliasDataType);
    cout << "Address Of the First shared_ptr  :    " << ptr5.get() << endl; // gives address of the pointer.

    shared_ptr<AliasDataType> ptr6(ptr5);
    cout << "Address Of the Second shared_ptr :    " << ptr6.get() << endl;
    cout << "Address Of the First shared_ptr after second shared_ptr is created :    " << ptr5.get() << endl;

    cout << "Pointers Count Pointing to the address of the First Pointer :    " << ptr5.use_count() << endl;
    cout << "Pointers Count Pointing to the address of the Second Pointer :    " << ptr6.use_count() << endl;

    ptr5.reset();       // reseting pointer to NULL.
    cout << "Address Of the First Pointer After resetting it :    " << ptr5.get() << endl;
    cout << "Address Of the Second Pointer After resetting first Pointer :    " << ptr6.get() << endl;
    cout << "Pointers Count Pointing to the address of the Second Pointer :    " << ptr6.use_count() << endl;
    cout << endl<<endl;

    //////////////////////////////////////////////////////////////////////////////////////////////////

    shared_ptr <WeakPointer_Working> ptr7(new WeakPointer_Working("Object_1"));
    shared_ptr <WeakPointer_Working> ptr8(new WeakPointer_Working("Object_2"));

    ptr7 -> linkToObject(ptr8);
    ptr8 -> linkToObject(ptr7);

    ptr7 -> showLink();
    ptr8 -> showLink();
    //////////////////////////////////////////////////////////////////////////////////////////////////

    return 0;
}
