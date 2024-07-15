#include <iostream>
using namespace std;

int main()
{
    int i = 0;
    int values[] = {1, 2, 3, 4, 10};

    cout << "Hello OutSide the Loop.... !" << endl;

    for (i = 0; 0; i++)     // exits without entering in for loop
    {
        cout << "Hello .... !" << endl;
    } 

    for (int x : values)    // Range based for loop (C++ 11)
    { 
        cout << x << endl;
    }

    //   for (i = 0; 1 ; i++)
    //   {
    //       cout << "Hello .... !" <<endl;                     // causes to run in infinite loop
    //   }

    //   for (i = 0; 'A'; i++)
    //   {
    //       cout << "Hello inside the loop.... !" <<endl;      // causes to run in infinite loop
    //   }

    return 0;
}
