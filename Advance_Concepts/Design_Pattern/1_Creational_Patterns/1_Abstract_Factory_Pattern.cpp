/** ********************************      IDEA of Abstract Factory Pattern     *****************************************
*
* Abstract Factory design pattern is one of the Creational pattern. Abstract Factory pattern is almost similar to
* Factory Pattern is considered as another layer of abstraction over factory pattern. Abstract Factory patterns
* work around a super-factory which creates other factories.
* Abstract factory pattern implementation provides us a framework that allows us to create objects that follow
*  a general pattern. So at runtime, abstract factory is coupled with any desired concrete factory which can
* create objects of desired type.
*
*   AbstractFactory : Declares an interface for operations that create abstract product objects.
*   ConcreteFactory : Implements the operations declared in the AbstractFactory to create concrete product objects.
*   Product : Defines a product object to be created by the corresponding concrete factory and implements the AbstractProduct interface.
*   Client : Uses only interfaces declared by AbstractFactory and AbstractProduct classes
*
************************************************************************************************************************/

#include <iostream>
using namespace std;


class Widget
{
public :
    virtual void Draw();
};

class LinuxButton : public Widget                           //   Concrete product family 1
{
public :
    void Draw() { cout << "Linux Button" << endl;}
};

class LinuxMenu : public Widget
{
public :
    void Draw() { cout << "Linux Menu" << endl;}
};

class WindowsButton : public Widget                         //   Concrete product family 2
{
public :
    void Draw() { cout << "Windows Button" << endl;}
};

class WindowsMenu : public Widget
{
public :
    void Draw() { cout << "Windows Menu" << endl;}
};

class Factory
{
public :
    virtual Widget * DrawButton();
    virtual Widget * DrawMenu();
};

class LinuxFactory : public Factory
{
public :
    Widget * DrawButton() { return new LinuxButton; }
    Widget * DrawMenu() { return new LinuxMenu; }
};

class WindowsFactory : public Factory
{
public :
    Widget * DrawButton() { return new WindowsButton; }
    Widget * DrawMenu() { return new WindowsMenu; }
};

class Client
{
private :
    Factory * ptrFactory;

public :
    Client (Factory * ptrFactory) { this -> ptrFactory = ptrFactory;}

    void DisplayWindow()
    {
        this -> ptrFactory -> DrawButton();
        this -> ptrFactory -> DrawMenu();
    }
};

enum Platform
{
    Linux = 1,
    Windows = 2
};

int main()
{
    int OS = 0;
    Factory * ptrFactory = NULL;
    Client * ptrClient = NULL;

    cout << " Please Enter the choice for OS " << endl;
    cout << " 1. Linux " << endl << " 2. Windows " << endl;
    cin >> OS;

    if (OS == Platform :: Linux) { ptrFactory = new LinuxFactory; }
    else if (OS == Platform :: Windows) { ptrFactory = new WindowsFactory; }
    else { cout << "Invalid Choice" << endl; }

    ptrClient = new Client(ptrFactory);
    delete ptrFactory;

    return 0;
};
