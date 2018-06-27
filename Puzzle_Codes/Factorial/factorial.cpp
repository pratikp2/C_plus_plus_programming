#include <iostream>
using namespace std;

int main()
{
    int fac_no,factorial = 1;

    cout << "Please enter the number whose factorial has to be calculated : ";
    cin >> fac_no;

    for (int i=0; i<fac_no; i++)
    {
        factorial = factorial*(fac_no-i);
    }

    cout << "Factorial of the " << fac_no << " is " << factorial<<endl;
    return 0;
}
