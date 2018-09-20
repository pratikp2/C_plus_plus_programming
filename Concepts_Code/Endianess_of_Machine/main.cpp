#include <iostream>
using namespace std;

int main()
{
    int a = 1;
    char * ptr = (char*)&a;

    if(*ptr) {cout << endl <<"Machine is Little Endian"<<endl;}
    else { cout << endl <<"Machine is Big Endian"<<endl;}

    return 0;
}
