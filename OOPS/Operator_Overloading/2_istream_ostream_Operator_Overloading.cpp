/***********************************************    Key Points    *******************************************************

1) cout is an object of ostream class and cin is an object istream class
2) These operators must be overloaded as a global function. And if we want to allow them to access private data members 
   of class, we must make them friend.
3) &in and &out are objects of the istream and ostream class respectively.(Exactly similar to cin and cout.)
4) The operators ‘<<' and '>>' are called like 'cout << ob1' and 'cin >> ob1'. So if we want to make them a member method,
   then they must be made members of ostream and istream classes, which is not a good option most of the time. Therefore,
   these operators are overloaded as global functions with two parameters, cout and object of user defined class.
   
 ************************************************************************************************************************/
# include <iostream>
using namespace std;

class Complex
{
		int real;
		int imag;

	public:
		Complex();
		friend istream & operator >> (istream &in, Complex &obj);
		friend ostream & operator << (ostream &out, const Complex &obj);
};

Complex :: Complex ()
{
	this -> real = 0;
	this -> imag = 0;
}

istream & operator >> (istream &in, Complex &Obj)
{
	cout << "Enter the Real part : " << endl;
	in >> Obj.real;
	cout << "Enter the Imagenary part : " << endl;
	in >> Obj.imag;
	return in;
}

ostream & operator << (ostream &out, const Complex &Obj)
{
	out <<	Obj.real;
	out <<  " + i" << Obj.imag << endl;
	return out; 
}

int main ()
{
	Complex ObjComplex;
	cin >> ObjComplex;
	cout << "The Complex object is : ";
	cout << ObjComplex;

	return 0;
}
