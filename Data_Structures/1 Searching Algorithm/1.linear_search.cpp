#include <iostream>
using namespace std;

# define MAX_SIZE 10
int linearSearch(int arr[],int data)
{
    int i=0;
    for (i=0; i<MAX_SIZE; i++){if(data == arr[i]){return i;}}
    return -1;
}

int main ()
{
    int data,index,arr[MAX_SIZE] = {1,2,3,4,5,6,7,8,9,10};
    cout << "Please enter the no. to be found : ";
    cin >> data;

    index = linearSearch(arr,data);

    if(index != -1) {cout << "Entered No. found at Location " << index+1 << endl;}
    else {cout << "Entered No. not Found" << endl;}

    return 0;
}
