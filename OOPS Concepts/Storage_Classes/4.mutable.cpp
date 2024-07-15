#include <iostream>
using namespace std;

class Explore
{
private:
    mutable int Val1;

public:
    Explore();
    void changeVal() const;
    void display() const;
    mutable int Val2;
};

Explore ::Explore()
{
    Val2 = 100;
    Val1 = 20;
}

void Explore ::changeVal() const
{
    Val1 = Val1 - 1;
}

void Explore ::display() const
{
    cout << "This is non const show Function" << endl;
}

int main()
{
    const Explore ObjExplore;
    ObjExplore.display();
    ObjExplore.changeVal(); // Changing via member function
    ObjExplore.Val2 = 200;  // Changing via object outside class
    ObjExplore.display();

    Explore ObjExplore2;
    ObjExplore2.display();

    return 0;
}

// Mutable keyword is used to change the value of member parametr in a const object.
// An object is mutable by default and can be made immutable uopn declaring const hence no need to make
// object mutable explicitly. Member functions can not be mutable.
