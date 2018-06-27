#include <iostream>
using namespace std;
class Vector
{
public :
    int x,y;
    Vector()
    {
        cout << "Default constructor Called" << endl;
    };
    Vector(int a,int b)
    {
    cout <<"Parameterized constructor Called" << endl;

    x=a;
    y=b;
    cout << "x = " << x << ",y = " << y << endl;
    }
    Vector operator+(const Vector&);

};
Vector Vector::operator+(const Vector& parameter)
{
 cout <<"OPerator Overloading  Called" << endl;
 cout <<"parameter.x = "<<parameter.x << endl;

    Vector temp;
    temp.x = x + parameter.x;
    //temp.y = y + parameter.y;
    //cout << temp.x  << endl;
    //cout << temp.y << endl;
 //return temp;
}

int main()
{
    Vector Vec1(4,2);
    Vector Vec2(0,2);
    Vector Vec3;
    Vec3 = Vec1 + Vec2;

   // cout<<"bdbb = "<< Vec3.x<< endl;
return 0;
}
