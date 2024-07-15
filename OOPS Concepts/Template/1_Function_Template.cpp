/*********************************************************************************************************
 *
 * This allows us to create a function template whose functionality can be adapted to more than one type
 * or class without repeating the entire code for each type.
 *
 *          template <class identifier> function_declaration;
 *          template <typename identifier> function_declaration;
 *
 * The only difference between both prototypes is the use of either the keyword class or the keyword
 * typename. Its use is indistinct, since both expressions have exactly the same meaning and behave
 * exactly the same way.
 *
 * ******************************************************************************************************/

#include <iostream>
#include <string.h>
using namespace std;

template <typename Any>
void Swap(Any &a, Any &b)
{
    Any s;
    s = a;
    a = b;
    b = s;
}

int main()
{

    int i = 10, j = 20;
    float x = 10.2, y = 20.2;
    string p = "Hi", q = "Hello";

    cout << endl;
    cout << "Value before swap A = " << i << " and B = " << j << endl;
    Swap(i, j);
    cout << "Value before swap A = " << i << " and B = " << j << endl;

    cout << endl;
    cout << "Value before swap X = " << x << " and Y = " << y << endl;
    Swap(x, y);
    cout << "Value before swap X = " << x << " and Y = " << y << endl;

    cout << endl;
    cout << "Value before swap P = " << p << " and Q = " << q << endl;
    Swap(p, q);
    cout << "Value before swap P = " << p << " and Q = " << q << endl;

    cout << endl;
    return 0;
}
