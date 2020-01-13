/** ***************************** Prototype ********************************************

    Declaration :   return_type(class :: *ptr_Name)(args) = &class :: FunctionName;
    Invoke      :   (ObjName.*ptr)(args);
                :   (ptrName->*ptr)(args)

****************************************************************************************/
#include<iostream>
using namespace std;

class Explore;
void (Explore :: *Fptr1)(void) = NULL;
void (Explore :: *Fptr2)(void) = NULL;

class Explore
{
private :
    void Function1()
    {
        cout << "Calling Private Function1" << endl;
    }

public :
    void Function2()
    {
        cout << "Calling Public Function2" << endl<<endl;
    }

    void Assignment()
    {
        Fptr1 = &Explore :: Function1;
        Fptr2 = &Explore :: Function2;
    }
};

int main()
{
    Explore ObjExplore;
    Explore ObjExplore1;
    Explore *ptrExplore = &ObjExplore1;

    ObjExplore.Assignment();
    (ObjExplore.*Fptr1)();  // Private Functions can also be called outside class using
                            // Function pointer to member function.
    (ObjExplore.*Fptr2)();

    ptrExplore -> Assignment();
    (ptrExplore ->*Fptr1)();
    (ptrExplore ->*Fptr2)();

    return 0;
}
