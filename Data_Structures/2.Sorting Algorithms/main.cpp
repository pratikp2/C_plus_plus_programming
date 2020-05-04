# include<iostream>

#define MAX_SIZE 7
using namespace std;

int* Bubble_Sort(int arr[])
{
    for (int i = 0; i < MAX_SIZE - 1; i++)
        for (int j = 0; j < MAX_SIZE - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
    return arr;
}

int* Selection_Sort(int arr[])
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        int minindex = i;
        for (int j = i + 1; j < MAX_SIZE; j++)
            if (arr[j] < arr[minindex])           
                minindex = j;
     
        int temp = arr[i];
        arr[i] = arr[minindex];
        arr[minindex] = temp;
    }
    return arr;
}

int* Insertion_Sort(int arr[])
{
    for (int i = 1; i < MAX_SIZE; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return arr;
}

int main()
{
    int arr[MAX_SIZE] = {1, 23, 41, 5, 14, 20, 33};
    int* sorted_arr = Bubble_Sort(arr);

    cout << "Sorted sequence : ";
    for (int i = 0; i < MAX_SIZE; i++)
        cout << sorted_arr[i] << " ";
    cout << endl;

    return 0;
}

// Time Complexity : О(n2) : n square

// To Optimize Code introduce a flag which checks weather swapping is happened or not.If There is no swapping in
// middle of complete checks it means the sequence is already sorted , no need to do more swapping.
