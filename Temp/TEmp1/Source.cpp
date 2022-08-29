#include <iostream>
#include <fstream>
#include <filesystem>
#include<memory>

using namespace std;

class AliasDataType
{};

shared_ptr<AliasDataType> ptr5(new AliasDataType);

shared_ptr<AliasDataType> TestFunction()
{
    
    cout << "Address Of the First shared_ptr  :    " << ptr5.get() << endl; // gives address of the pointer.

    shared_ptr<AliasDataType> ptr6(ptr5);
    shared_ptr<AliasDataType> ptr7(ptr5);
    cout << "Address Of the Second shared_ptr :    " << ptr6.get() << endl;
    cout << "Pointers Count Pointing to the address of the Second Pointer :    " << ptr6.use_count() << endl;
    cout << endl << endl;

   return ptr7;
}

int main()
{

    shared_ptr<AliasDataType> ptr7 = TestFunction();
    
    cout << "************************ MAIN ****************************************** " << endl;
    cout << "Address Of the Second Pointer After resetting first Pointer :    " << ptr7.get() << endl;
    cout << "Pointers Count Pointing to the address of the Second Pointer :    " << ptr7.use_count() << endl;
    cout << endl << endl;

	return 0;
}