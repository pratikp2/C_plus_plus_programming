#include <iostream>
using namespace std;

class Parent
{
	public :
	Parent() {cout << "Constructor of Parent Called" << endl;}
	~Parent(){cout << "Destructor of Parent called" << endl;}
};

class Child : public Parent
{
	public :
	Child() {cout << "Constructor of Child Called" << endl;}
	~Child(){cout << "Destructor of Child called" << endl;}
};

class Base
{
	public :
	Base() {cout << "Constructor of Base Called" << endl;}
	virtual ~Base(){cout << "Destructor of Base called" << endl;}
};

class Derived : public Base
{
	public :
	Derived() {cout << "Constructor of Derived Called" << endl;}
	~Derived(){cout << "Destructor of Derived called" << endl;}
};

int main()
{
	Parent * ptrParent = new Child();
	if (ptrParent != NULL)
	{
		delete ptrParent;			// 	<- Need of virtual Destructor
		ptrParent = NULL;
	}
	
	cout << endl;
	
	Base * ptrBase = new Derived();
	if (ptrBase != NULL)
	{
		delete ptrBase;
		ptrBase = NULL;
	}
	
	return 0;
}

// In Case of Classes Parent and Child when creating Child object via Parent pointer and deleting the pointer.
// The destruction of Child class does not happen.

// In Case of Classes Base and Derived when creating Derived object via Base pointer and deleting the pointer.
// The destruction of Derived class takes place because Base Destructor is virtual.

// Virtual Destructor is use full when deleting all clsses in inheritance hierarchy because if Destructor is not virtual
// compiler will only delete Base class memory as pointer is of type base class at such time Derived classes memory stays
// as it is. 