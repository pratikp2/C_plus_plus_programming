#include <iostream>
using namespace std;

int* add(int a[],int b[],int n);


int main()
{
 int arrSize=8;

 int arr[]={1,2,3,4,5,6,7,8};
 int arr1[]={1,2,3,4,5,6,7,8};
 int total[8]={0};
 int *addr= add(arr,arr1,arrSize);


 for(int i=0;i<8;i++)
    {
     total[i]=*addr;
     cout<<total[i]<<endl;
     (++addr);
    }
    return 0;
}



int* add(int a[],int b[],int n)
{
    for(int i=0;i<n;i++)
    {
       a[i]=b[i]+a[i];
    }
    return a;
}


//int main ()                <-------------------------------------------------           Update array Code
//{
//  int numbers[5];
//  int * p;
//  p = numbers;  *p = 10;
//  p++;  *p = 20;
//  p = &numbers[2];  *p = 30;
//  p = numbers + 3;  *p = 40;
//  p = numbers;  *(p+4) = 50;
//  for (int n=0; n<5; n++)
//    cout << numbers[n] << ", ";
//  return 0;
//}​
