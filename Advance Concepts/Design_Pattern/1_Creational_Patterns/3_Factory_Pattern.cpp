/** ***************************************     IDEA of Factory Pattern     ********************************************
*
*   1) The idea is to use a static member-function (static factory method) which creates & returns instances, hiding the
*      details of class modules from user.
*   2) A factory pattern is one of the core design principles to create an object, allowing clients to create objects
*      of a library in a way such that "it doesn’t have tight coupling with the class hierarchy of the library".
*   3) "Data" required by the classes may change (In the case enum and Wheeler Classes) , but the Contract between
*       Factory class and client class remains same.
*
************************************************************************************************************************/

#include <iostream>
using namespace std;

enum VehicleType
{
    TwoWheelar = 0,
    ThreeWheelar,
    FourWheelar
};

class Vehicle   // Factory Class
{
public :
    virtual void print()= 0;
    static Vehicle* create(VehicleType type);
};

class Class_TwoWheelar : public Vehicle
{
    void print(){cout << "I am Two Wheeler Class"<<endl;}
};

class Class_ThreeWheelar : public Vehicle
{
    void print(){cout << "I am Three Wheeler Class"<<endl;}
};

class Class_FourWheelar : public Vehicle
{
    void print(){cout << "I am Four Wheeler Class"<<endl;}
};

Vehicle * Vehicle :: create(VehicleType type)
{
    if (type == TwoWheelar) { return new Class_TwoWheelar(); }
    else if(type == ThreeWheelar) { return new Class_ThreeWheelar(); }
    else if (type == FourWheelar) { return new Class_FourWheelar(); }
}

class Client    // Client Class
{
public :
    Client()
    {
        VehicleType type = TwoWheelar;
        pVehicle = Vehicle :: create(type);
    }
    Vehicle * getVehicle(){return pVehicle;}
    ~Client()
    {
        if(pVehicle)
        {
            delete pVehicle;
            pVehicle = NULL;
        }
    }

private :
    Vehicle *pVehicle;

};
int main()
{
    Client *pClient = new Client();
    Vehicle *pVehicle = pClient -> getVehicle();
    pVehicle -> print();
    return 0;
}
