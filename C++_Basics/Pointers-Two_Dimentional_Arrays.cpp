#include<iostream>
using namespace std;

int main()
{
    int i,j;
    int M = 4;
    int N = 4;
    int count = 0;
    int **A = new int*[M];

    for (i=0; i<M; i++)
    {
        A[i] = new int[N];
        for (j=0; j<N; j++)
        {
            A[i][j] = count;
            count++;
            cout << A[i][j] << "\t\t";
        }
        cout << endl;
    }

    for (i=0; i<M; ++i) { delete []A[i]; }
    delete []A;

    cout <<  endl <<endl;

    for (i=0; i<M; i++)
    {
        for (j=0; j<N; j++)
        {
            cout << A[i][j] << "\t\t";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
