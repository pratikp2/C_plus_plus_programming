#include <iostream>
#include <cstring>
using namespace std;

void RecursionBackTracking(int arr[], string s, int index)
{
    if (index < 0)
    {
        cout << s << endl;
        return;
    }

    RecursionBackTracking(arr, s, index-1);
    RecursionBackTracking(arr, s + " " + to_string(arr[index]), index-1);
}

int main()
{
    int size = 10;
    //int arr[size] = {2,4,6,10,15};
    int arr[size] = {4,14,15,18,29,32,36,82,95,95};
    RecursionBackTracking(arr, "", size-1);

    return 0;
}
