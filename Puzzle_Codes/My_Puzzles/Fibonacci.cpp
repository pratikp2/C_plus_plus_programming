# include <iostream>
using namespace std;

int main()
{
    int order;
    cout << "Enter the order of the Fibonacci Series: ";
    cin >> order;
    cout << endl;

    int arr[order];
    arr[0] = 0;
    arr[1] = 1;

    for (int i=2; i<order; i++)
    {
        arr[i] = arr[i-1] + arr[i-2];
    }

    for (int i=0; i<order; i++)
    {
        cout << arr[i] <<" ";
    }
        cout << endl;

    return 0;
}
