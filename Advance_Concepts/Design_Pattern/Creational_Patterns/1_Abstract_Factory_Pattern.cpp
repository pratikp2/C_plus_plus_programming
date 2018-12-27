/** ********************************      IDEA of Abstract Factory Pattern     *****************************************
*
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
    Widget * DrawButton() { return new LinuxButton; }
    Widget * DrawMenu() { return new LinuxMenu; }
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
