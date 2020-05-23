#include <iostream>
using namespace std;

const int size1D = 8;
const int size2D = 4;
const int size3D = 2;

void show1DArray(int []);
void show2DArray(int [size2D][size2D]);              // const size is needed while passing Multidimentional arrays
void show3DArray(int [size3D][size3D][size3D]);      // array as an argument

int main()
{
    int arr1D[]={1,2,3,4,5,6,7,8};
    show1DArray(arr1D);

    cout << endl << endl;

    int arr2D[size2D][size2D] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    show2DArray(arr2D);

    cout << endl << endl;

    int arr3D[size3D][size3D][size3D] = {0,1,2,3,4,5,6,7};
    show3DArray(arr3D);

    return 0;
}

void show1DArray(int arr[size1D])
{
    cout << "Printing 1D Array : " << endl;
    for(int i=0; i<size1D; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void show2DArray(int arr[size2D][size2D])
{
    cout << "Printing 2D Array : " << endl;
    for(int i=0; i<size2D; i++)
    {
        for(int j=0; j<size2D; j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
}

void show3DArray(int arr[size3D][size3D][size3D])
{
    cout << "Printing 3D Array : " << endl;
    for(int i=0; i<size3D; i++)
    {
        for(int j=0; j<size3D; j++)
        {
            for(int k=0; k<size3D; k++)
            {
                cout << arr[i][j][k] << "  ";
            }
            cout << endl;
        }
        cout << endl << endl;
    }
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
