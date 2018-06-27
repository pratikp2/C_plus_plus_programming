/***********************************************    Key Points    *******************************************************

    1) "Factory Class" has static method to handover the "Data" to Client class.
    2) "Client Class" can ask for the "Data" via function (In this Case via Constructor Directly)
    3) "Data" required by the classes may change (In the case enum and Wheeler Classes) , but the Contract between
       "Factory and Client classes" remains unchanged (static method in factory class).
    4) https://www.geeksforgeeks.org/design-patterns-set-2-factory-method/

************************************************************************************************************************/

#include <iostream>
using namespace std;

enum VehicleType
 {
   TwoWheelar = 0,
   ThreeWheelar,
   FourWheelar
 };
class Vehicle
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
    if (type == TwoWheelar)
    {
        return new Class_TwoWheelar();
    }
    else if(type == ThreeWheelar)
    {
        return new Class_ThreeWheelar();
    }
    else if (type == FourWheelar)
    {
        return new Class_FourWheelar();
    }
}

class Client
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
