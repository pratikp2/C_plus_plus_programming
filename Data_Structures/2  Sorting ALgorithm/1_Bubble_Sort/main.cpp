# include<iostream>         // BUBBLE SORT //
using namespace std;

int main()
{
    int temp,i,j,index = 7;
    int sort_arr[index] = {1,23,41,5,14,20,33};

    for(i=0; i<index-1; i++)
    {
        for(j=0; j<index-i-1; j++)
        {
            if (sort_arr[j] > sort_arr[j+1])
            {
                temp = sort_arr[j];
                sort_arr[j] = sort_arr[j+1];
                sort_arr[j+1] = temp;
            }
        }
    }

    cout << "Sorted sequence using Bubble Sort : ";
    for (i=0; i<index; i++)
    { cout << sort_arr[i] << " ";}
    cout << endl;

    return 0;
}

// To Optimize Code introduce a flag which checks weather swapping is happened or not.If There is no swapping in
// middle of complete checks it means the sequence is already sorted , no need to do more swapping.
