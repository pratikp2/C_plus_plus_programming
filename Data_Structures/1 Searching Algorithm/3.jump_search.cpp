#include <iostream>
#include <bits/stdc++.h>
using namespace std;

# define MAX_SIZE 20
int jumpSearch(int arr[], int data)     // Complexity O(√n)
{
    int step = sqrt(MAX_SIZE), prev = 0;

    while(arr[min(step,MAX_SIZE)-1] <  data)
    {
        prev = step;
        step = step + sqrt(MAX_SIZE);
        if(prev >= MAX_SIZE){return -1;}
    }

    while(arr[prev] < data)
    {
        prev++;
        if (prev == min(step,MAX_SIZE))
        {return -1;}
    }

    if(arr[prev] == data){return prev;}
    return -1;
}

int main ()
{
    int data,index,arr[MAX_SIZE] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    cout << "Please enter the no. to be found : ";
    cin >> data;

    index = jumpSearch(arr,data);

    if(index != -1) {cout << "Entered No. found at Location " << index+1 << endl;}
    else {cout << "Given Data not Found" << endl;}

    return 0;
}
