/** *************************************************************************************

    - LONG stores numbers as numeric values, including decimal, fractional, and whole numbers.
    - DOUBLE stores double-precision floating point number values.
    - STRING stores alphanumeric characters as text.
    - DATETIME stores year, month, day, hour, minute, and second values.
    - DATE stores year, month, and day values.
    - TIME stores hour, minute, and second values.

    Beyond that, DOUBLE stores decimal values with a higher precision (24-53 digits) than a FLOAT type.
    LONG is used when a wider range than INT is needed.

***************************************************************************************** */

#include <iostream>
using namespace std;

int main() {

    signed int a = 1;       // Can Hold numbers with signs
    unsigned int b = 1;     // Can hold numbers woth only positive sign

    unsigned char c = 'A';  // Ranges from 0 to 255
    signed char d = 'A';    // Ranges from -128 to 127

    long int e = 1;         // Can hold 32 bits i.e, 4 bytes
    long long int f = 1;    // Can hold 64 bits i.e, 8 bytes

    cout << endl;

    cout << "Size of int            : " << sizeof(int) << endl;
    cout << "Size of signed int     : " << sizeof(signed int) << endl;
    cout << "Size of unsigned int   : " << sizeof(unsigned int) << endl<< endl;

    cout << "Size of short          : " << sizeof(short) << endl;
    cout << "Size of signed short   : " << sizeof(signed short) << endl;
    cout << "Size of unsigned short : " << sizeof(unsigned short) << endl<< endl;

    cout << "Size of char           : " << sizeof(char) << endl;
    cout << "Size of signed char    : " << sizeof(signed char) <<endl;
    cout << "Size of unsigned char  : " << sizeof(unsigned char) << endl << endl;

    cout << "Size of long int       : " << sizeof(long int) << endl;
    cout << "Size of long long int  : " << sizeof(long long int) << endl<< endl;
    //cout << "Size of long long int: " << sizeof(long long long int) << endl<< endl; too long for GCC

    cout << "Size of float          : " << sizeof(float) << endl;
    cout << "Size of double         : " << sizeof(double) << endl <<endl;

    return 0;
}

/*
Type                    Typical Bit Width	Typical Range

char	                1 byte	            -127 to 127 or 0 to 255
unsigned char	        1 byte	            0 to 255
signed char	            1 byte	            -127 to 127

short int	            2 bytes	            -32768 to 32767
unsigned short int	    2 bytes	            0 to 65,535
signed short int	    2 bytes	            -32768 to 32767

int	                    4 bytes	            -2147483648 to 2147483647
unsigned int	        4 bytes	            0 to 4294967295
signed int	            4 bytes	            -2147483648 to 2147483647

float	                4 bytes	

long int	            8 bytes	            -9223372036854775808 to 9223372036854775807
signed long int	        8 bytes	            same as long int
unsigned long int	    8 bytes	            0 to 18446744073709551615

long long int	        8 bytes	            -(2^63) to (2^63)-1
unsigned long long int	8 bytes	            0 to 18,446,744,073,709,551,615

double	                8 bytes	
long double	            12 bytes	

wchar_t	                2 or 4 bytes	    1 wide character
*/