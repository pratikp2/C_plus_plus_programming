#include <iostream>
using namespace std;

class Explore
{
private :
    int A = 10,a;                   //
    const string Hold = "Hello";    // Allows defination inside class body.
    float fraction = 2.5f, frac;    //

public :
    Explore(int a, float frac)
    {
        this->a = a;
        this->frac = frac;
    }

    Explore():Explore(25,5.5f)      // Constructor Deligation : Attribues can be instantiated by calling other
    {                               // contructors.

    }

    void printVal()
    {
        cout << "A      : " << A << endl;
        cout << "a      : " << a << endl;
        cout << "Hold   : " << Hold << endl;
        cout << "Float1 : " << fraction << endl;
        cout << "Float2 : " << frac << endl;
    }
};

int main()
{
    Explore objExplore;
    objExplore.printVal();
    return 0;
}
