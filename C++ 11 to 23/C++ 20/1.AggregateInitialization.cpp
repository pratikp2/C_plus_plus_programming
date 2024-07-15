#include<iostream>
using namespace std; 

struct base1
{
    int b1, b2 = 42;
};

struct base2
{
    base2()
    {
        b3 = 42;
    }

    int b3;
};

struct derived : base1, base2
{
    int d;
};

int main(int argc, char** argv)
{
    derived d1{ {1, 2}, {}, 4 }; // initializes d1.b1 with 1, d1.b2 with 2,
                           //             d1.b3 with 42, d1.d with 4
    derived d2{ {}, {}, 4 };     // initializes d2.b1 with 0, d2.b2 with 42,
                               //             d2.b3 with 42, d2.d with 4
	return 0;
}