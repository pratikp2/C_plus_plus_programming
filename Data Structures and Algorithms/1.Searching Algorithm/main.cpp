#include <iostream>
#include <algorithm>

using namespace std;
# define MAX_SIZE 20

int linearSearch(int arr[], int data) // Complexity is O(n)
{
    int i = 0;
    for (i = 0; i < MAX_SIZE; i++)
        if (data == arr[i])
            return i;
    return -1;
}

int binarySearch(int arr[], int data, int lb, int ub)  // Complexity is O(log n)
{
    cout << "Traces || Data : " << data << ", Updated Lower Bound : " << lb << ",Updated Upper Bound : " << ub << endl;
    int mid;
    mid = lb + (ub - lb) / 2;

    if (arr[mid] == data) return mid;
    else if (arr[mid] > data) return binarySearch(arr, data, lb, mid - 1);
    else if (arr[mid] < data) return binarySearch(arr, data, mid + 1, ub);
    else return -1;
}

int jumpSearch(int arr[], int data)     // Complexity O(√n)
{
    int step = sqrt(MAX_SIZE), prev = 0;

    while (arr[min(step, MAX_SIZE) - 1] < data)
    {
        prev = step;
        step = step + sqrt(MAX_SIZE);
        if (prev >= MAX_SIZE) 
            return -1;
    }

    while (arr[prev] < data)
    {
        prev++;
        if (prev == min(step, MAX_SIZE))
            return -1;
    }

    if (arr[prev] == data) { return prev; }
    return -1;
}

int main()
{
    int data, index, arr[MAX_SIZE] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
    cout << "Please enter the no. to be found : ";
    cin >> data;

    index = linearSearch(arr, data);

    if (index != -1) { cout << "Entered No. found at Location " << index + 1 << endl; }
    else { cout << "Entered No. not Found" << endl; }

    return 0;
}
