/** ************************************      IDEA of Singleton Pattern     **********************************************

    1) Both getInstance and releaseInstance will be static.
    2) Created Object will be static.
    3) Constructor will have definition and will be Private so that no one can create Object Directly
    4) While maintaining referenceCount, it will also be static.

 ************************************************************************************************************************/

#include <iostream>
using namespace std;

class Singleton
{
public :
    static Singleton* getInstance();
    static Singleton* releaseInstance();

private :
    static Singleton* objInstance;
    Singleton(){}
};

Singleton* Singleton :: objInstance = NULL;

Singleton* Singleton :: getInstance()
{
    if (objInstance == NULL)
    {
        objInstance = new Singleton();
    }
    return objInstance;
}

Singleton* Singleton :: releaseInstance()
{
    if (objInstance != NULL)
    {
        delete objInstance;
        objInstance = NULL;
    }
}

int main ()
{
    Singleton * One = Singleton :: getInstance();
    cout << "Address for pointer One is : " << &One <<endl;     // Can be implemented using Smatr pointers
    cout << "Address for object One is : " << One <<endl;

    Singleton * Two = Singleton :: getInstance();
    cout << "Address for pointer Two is : " << &Two <<endl;
    cout << "Address for object Two is : " << Two <<endl<<endl;

    One = Singleton :: releaseInstance();
    cout << "Address for object One After releasing Instance is : " << One <<endl;

    Two = Singleton :: releaseInstance();
    cout << "Address for object Two After releasing Instance is : " << Two <<endl;

    return 0;
}
