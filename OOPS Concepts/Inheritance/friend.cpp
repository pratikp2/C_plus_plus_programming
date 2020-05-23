/** ************************************************************************************************
 *   Friend function : Able to access all the private member parameters for the class SuperSet
 *                     Friend functions is not member function of the class in which they are declared
 *
 *   Friend Class : All the member function of the NeedAccess will becomes the freind functions of
 *                  class SuperSet
***************************************************************************************************/
#include <iostream>
#include <strings.h>
using namespace std;

class NeedAccess;
class SuperSet
{
private :
    int Age;
    string Name;

public:
    SuperSet()
    {
        Age = 25;
        Name = "Pratik";
    }
    friend void getParam(SuperSet ObjSuperSet);
    friend class NeedAccess;
};

class NeedAccess
{
public :
    void getParam(SuperSet ObjSuperSet)
    {
        cout << "Printing from the freind Class" << endl;
        cout << "Name of the Object is  : " << ObjSuperSet.Name<<endl;
        cout << "Age of the Object is   : " << ObjSuperSet.Age<<endl<<endl;
    }
};

void getParam(SuperSet ObjSuperSet)
{
    cout << "Printing from the freind Function" << endl;
    cout << "Name of the Object is  : " << ObjSuperSet.Name<<endl;
    cout << "Age of the Object is   : " << ObjSuperSet.Age<<endl<<endl;
}

int main()
{
    SuperSet ObjSuperSet;
    NeedAccess ObjNeedAccess;

    ObjNeedAccess.getParam(ObjSuperSet);
    getParam(ObjSuperSet);

    return 0;
}
