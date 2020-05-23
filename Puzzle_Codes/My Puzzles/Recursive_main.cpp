# include <iostream>
using namespace std;

int a = 0;

int main()
{
    while(a < 10)
    {
        a++;
        cout<< "Hello"<<endl;
        main();
    }
    return 0;
}

// main() function can be called from anywhere.


//int main()
//{
//    while(1)
//    {
//        cout<< "Hello"<<endl;
//        main();
//    }
//    return 0;
//}

// in above code main will get called recursively and when system runs out of
// memory it will throw core dump with seg fault.
