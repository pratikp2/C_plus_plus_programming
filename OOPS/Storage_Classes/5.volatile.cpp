# include <iostream>
using namespace std;

int main(void)
{
    const int local = 10;
    int *ptr = (int*) &local;
    cout << "Initial value of local     : " << local << endl;
    cout << "Initial value of &local    : " << &local << endl;
    cout << "Initial value of * ptr     : " << *ptr << endl;
    cout << "Initial value of ptr       : " << ptr << endl<< endl;


    *ptr = 100;
    cout << "Modified value of local    : " << local << endl;
    cout << "Modified value of &local   : " << &local << endl;
    cout << "Modified value of * ptr    : " << *ptr << endl;
    cout << "Modified value of ptr      : " << ptr << endl;

    return 0;
}
