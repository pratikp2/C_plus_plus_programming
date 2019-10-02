/** ***********************************************************************************************
	
		Construction Sequence :
		
		1. Base Constructed
		2. Derived Constructed
		3. Derived Destructed
		4. Base Destructed
		
**************************************************************************************************/
#include <iostream>
using namespace std;

class Parent_1
{
	public :
	Parent_1() {cout << "Constructor of Parent_1 Called" << endl;}
	~Parent_1(){cout << "Destructor of Parent_1 called" << endl;}
};

class Parent_2
{
	public :
	Parent_2() {cout << "Constructor of Parent_2 Called" << endl;}
	~Parent_2(){cout << "Destructor of Parent_2 called" << endl;}
};

class Child : public Parent_2, public Parent_1 	// Base Classes Constructions sequence depends upon sequence of inheritance
{
	public :
	Child() {cout << "Constructor of Child Called" << endl;}
	~Child(){cout << "Destructor of Child called" << endl;}
};

int main()
{
    Child ObjChild;

    // Sequence :
    // Parent_2()
    // Parent_1()
    // Child()
    // ~Child()
    //~Parent_1()
    //~Parent_2()

	return 0;
}

