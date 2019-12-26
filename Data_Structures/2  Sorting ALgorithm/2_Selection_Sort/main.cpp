# include<iostream>         // SELECTION SORT //
using namespace std;

int main()
{
    int temp,i,j,index = 7,minindex = 0;
    int sort_arr[index] = {1,23,41,5,14,20,33};

    for(i=0; i<index; i++)
    {
        minindex = i;
        for(j=i+1; j<index; j++)
        {
            if (sort_arr[j] < sort_arr[minindex])
            {
                minindex = j;
            }
        }
    temp = sort_arr[i];
    sort_arr[i] = sort_arr[minindex];
    sort_arr[minindex] = temp;
    }

    cout << "Sorted sequence using Selection Sort : ";
    for (i=0; i<index; i++)
    { cout << sort_arr[i] << " ";}
    cout << endl;

    return 0;
}

// Time Complexity : О(n2) : n square
