# include <iostream>
using namespace std;

int main()
{
   int i = 0;

   cout << "Hello OutSide the Loop.... !" <<endl;

   for (i = 0; 0 ; i++) { cout << "Hello .... !" <<endl; }  // exits without entering in for loop

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
