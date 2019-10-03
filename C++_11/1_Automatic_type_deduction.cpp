# include <iostream>
# include <strings.h>
using namespace std;

int main()

{
    auto a = 20;
    auto b = 20.10;
    auto c = 'C';
    auto d = "Pratik Patil";

    cout << "Value For A : " << a << endl;
    cout << "Value For B : " << b << endl;
    cout << "Value For C : " << c << endl;
    cout << "Value For D : " << d << endl;
}


// As shown automatic type deduction can initilize the object value depending upon what type of datda is
// given to the new data type woth the help of auto storage class.
