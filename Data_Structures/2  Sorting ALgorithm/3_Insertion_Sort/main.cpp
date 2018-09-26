// SELECTION SORT //
# include<iostream>
using namespace std;

int main()
{
    int key,i,j,index = 7;
    int sort_arr[index] = {1,23,41,5,14,20,33};

    for(i=1; i<index; i++)
    {
        key = sort_arr[i];
        j = i-1;
        while (j>=0 && key<sort_arr[j])
        {
            sort_arr[j+1] = sort_arr[j];
            j = j-1;
        }
        sort_arr[j+1] = key;
    }

    cout << endl <<"Sorted sequence using Selection Sort : ";
    for (i=0; i<index; i++)
    { cout << sort_arr[i] << " ";}
    cout << endl <<  endl;

    return 0;
}

