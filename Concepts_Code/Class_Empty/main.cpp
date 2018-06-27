#include <iostream>
using namespace std;

class Empty
{

};

class Filled
{
public :
    int p;
    double q;
    char x = 'a';
    char y = 'a';
    char z = 'a';


};

int main()
{
    Empty A;
    cout << "The size of empty class object = "<< sizeof(A) << endl<<endl;

    //Behavior of that object is also nothing, but compiler assigns a unique address
    //to that object. Memory in Computer is always organized in the form of bytes and
    //minimum memory available at object address location is 1 byte. That's why size
    //of object of empty class is 1 byte


    Filled B;
    cout << "The size of Filled class object integer= "<< sizeof(B.p) << endl;
    cout << "The size of Filled class object double= "<< sizeof(B.q) << endl;
    cout << "The size of Filled class object character= "<< sizeof(B.x) << endl;
    cout << "The size of Filled class object character= "<< sizeof(B.y) << endl;
    cout << "The size of Filled class object character= "<< sizeof(B.z) << endl;
    cout << "The size of Filled class object = "<< sizeof(B) << endl<< endl;

    return 0;

}
