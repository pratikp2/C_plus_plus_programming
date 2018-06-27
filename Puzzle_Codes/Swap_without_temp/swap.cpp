#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    int b = 8;

    cout << "Value before swap : A = "<<a<<" and B = "<<b<<endl;

    a = a+b;
    b = a-b;
    a = a-b;

    cout << "Value after swap : A = "<<a<<" and B = "<<b<<endl;

    return 0;
}
