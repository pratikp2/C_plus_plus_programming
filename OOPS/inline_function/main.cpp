#include <iostream>

using namespace std;

inline int sq(int x)
{
    return x*x;
}

int main()
{
    int a=8;
    int b=7;

    int c=sq(a);
    int d=sq(10+b);

    cout<<c<<"     "<<d<<endl;
    return 0;
}

