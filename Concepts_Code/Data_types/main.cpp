#include <iostream>

using namespace std;

int main()
{
    int a = 1;
    signed int b = 1;
    unsigned int c = 1;
    long int d = 1;
    long long int e = 1;

    float f = 1;
    double g = 1;

    char h = 'A';


    cout << "Size of int " << sizeof(a) << endl;
    cout << "Size of signed int " << sizeof(b) << endl;
    cout << "Size of unsigned int " << sizeof(c) << endl;
    cout << "Size of long int " << sizeof(d) << endl;
    cout << "Size of long long int " << sizeof(e) << endl;
    cout << "Size of float " << sizeof(f) << endl;
    cout << "Size of double " << sizeof(g) << endl;
    cout << "Size of char " << sizeof(h) << endl;

    return 0;

}

