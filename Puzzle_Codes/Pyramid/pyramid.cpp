#include<iostream>
using namespace std;

int main()
{
    int row;
    cout << "Enter the order of Pyramid: ";
    cin >> row;

    for (int i=1; i<=row; i++)
    {
        for (int k=0; k<(row-i); k++)
        {
            cout << " ";
        }
        for (int j=1; j<=i; j++)
        {
            cout << "* ";
        }
        cout << "\n";
    }

    return 0;
}

