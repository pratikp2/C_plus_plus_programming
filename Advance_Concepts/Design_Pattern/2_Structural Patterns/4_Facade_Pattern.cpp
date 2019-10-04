/** ********************************      IDEA of Abstract Factory Pattern     ***************************************
**
*
* Facade pattern: provides a unified - simplified interface to a complex subsystem or set of interfaces.
* It provides a higher level interface simultaneously decoupling the client from the complex subsystem.
*
* A facade can:
*   1. improve the readability and usability of a software library by masking interaction with more complex
*       components behind a single (and often simplified) API
*   2. provide a context-specific interface to more generic functionality (complete with context-specific input
*       validation)
*   3. serve as a launching point for a broader refactor of monolithic or tightly-coupled systems in favor of more
*       loosely-coupled code.
*
*   Developers often use the facade design pattern when a system is very complex or difficult to understand because
*   the system has many interdependent classes or because its source code is unavailable. This pattern hides the
*   complexities of the larger system and provides a simpler interface to the client. It typically involves a single
*   wrapper class that contains a set of members required by the client. These members access the system on behalf of
*   the facade client and hide the implementation details.
*
************************************************************************************************************************/

#include <iostream>
using namespace std;

class CPU
{
public:
    CPU(){}
    void Freeze(){ cout<<"Please Standby"<<endl; }
    void Jump(long position){ cout << "Jumping to programme position : " << position << endl;}
    void Execute() {cout << "System Started....!" << endl;}
};

class Memory
{
    public:
    Memory(){}
    void Load(long position, char * data)
    {
        cout << "Loading essential Programs..." << endl;
        position++;
        data++;
    }

};

class HardDrive
{
public:
    HardDrive(){}
    char * Read(long location, size_t size)
    {
        cout << "Reading essential Programs..." << endl;
        size++;
        char * pos = (char*)location;
        return pos;
    }
};

class ComputerFacade
{
public:
    ComputerFacade()
    {
        ptrCPU = new CPU();
        ptrMemory = new Memory();
        ptrHardDrive = new HardDrive();
    }

    ~ComputerFacade()
    {
        if(ptrCPU != nullptr)
        {
            delete ptrCPU;
            ptrCPU = nullptr;
        }

        if(ptrMemory != nullptr)
        {
            delete ptrMemory;
            ptrMemory = nullptr;
        }

        if(ptrHardDrive != nullptr)
        {
            delete ptrHardDrive;
            ptrHardDrive = nullptr;
        }
    }

    void StartBootLoader()
    {
        ptrCPU->Freeze();
        ptrMemory->Load(bootAddress,ptrHardDrive->Read(bootAddress,progSize));
        ptrCPU->Jump(bootAddress);
        ptrCPU->Execute();
    }

    void ShutDown()
    {

    }

private:
    CPU * ptrCPU;
    Memory * ptrMemory;
    HardDrive * ptrHardDrive;
    long bootAddress = 0XFF;
    size_t progSize = 60;
};

int main()
{
    ComputerFacade objComputerFacade;
    objComputerFacade.StartBootLoader();
    objComputerFacade.ShutDown();
    return 0;
}
