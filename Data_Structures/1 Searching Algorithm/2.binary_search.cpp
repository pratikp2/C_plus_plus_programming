#include <iostream>
using namespace std;

# define MAX_SIZE 20
int binarySearch(int arr[], int data, int lb, int ub)
{
    cout << "Traces || Data : " << data << ", Updated Lower Bound : " << lb << ",Updated Upper Bound : " << ub << endl;
    int mid;
    mid = lb + (ub-lb)/2;

    if(arr[mid] == data) return mid;
    else if (arr[mid]>data) return binarySearch(arr,data,lb,mid-1);
    else if (arr[mid]<data) return binarySearch(arr,data,mid+1,ub);
    else return -1;
}

int main ()
{
    int data,index,arr[MAX_SIZE] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    cout << "Please enter the no. to be found : ";
    cin >> data;

    index = binarySearch(arr,data,0,(MAX_SIZE-1));

    if(index != -1) {cout << "Entered No. found at Location " << index+1 << endl;}
    else {cout << "Given Data not Found" << endl;}

    return 0;
}
