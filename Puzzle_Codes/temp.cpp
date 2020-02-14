#include <iostream>
#include <cstring>
#include <string>

#define SIZE 4
#define TARGET 14
using namespace std;

int RecursionBackTracking(int arr[], int index, int sum, string s)
{
    if (index > SIZE-1 || sum == TARGET)
        return sum;

    int sum1 = RecursionBackTracking(arr, index+1, sum, s);

    if (sum + arr[index+1] <= TARGET)
        sum = RecursionBackTracking(arr, index+1, sum + arr[index], s + " " + to_string(arr[index]));

    sum = (sum>sum1) ? sum : sum1;

    cout << sum << endl;
    return sum;
}

int main()
{
    int arr[SIZE] = {2,5,6,8};
    //int arr[SIZE] = {4,14,15,18,29,32,36,82,95,95};
    cout << RecursionBackTracking(arr, 0,arr[0], "");

    system("pause");
    return 0;
}
