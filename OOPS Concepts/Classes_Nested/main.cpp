#include<iostream>
using namespace std;

class Enclosing {
    public :

        Enclosing() {cout << "In Enclosing Class"<<endl;}

        class Nested {
            public :
                Nested() {cout << "In Nested Class"<<endl;}

                class NestedInner {
                    public :
                        NestedInner() {cout << "In NestedInner Class"<<endl;}
                };
        };
};

int main()
{
    Enclosing obj1;
    Enclosing :: Nested obj2;
    Enclosing :: Nested :: NestedInner obj3;

    return 0;
}

