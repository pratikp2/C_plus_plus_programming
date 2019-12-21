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

// Little Endian : The Most Significatn byte is stored at Last of byte of the allocated Memory. i,e. at higher address.
// eg for a hexadecomal No 0X12345678.
//      Address     00      01      02      03
//      Digits      78      56      34      12

// Big Endian : On other Hand for big Endian Most Significatn byte is stored at first of byte of the allocated Memory.
// i,e. at lower address.
// eg for a hexadecomal No 0X12345678.
//      Address     00      01      02      03
//      Digits      12      34      56      78
