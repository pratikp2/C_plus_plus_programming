/** *******************************************************************************************

	Virtual table is nothing but an array of the function pointer pointing to the functions
	present in the classes. When using virtual function access specifiers get by pass as
	virtual table has a function pointer pointing to those function. Hence private functions
	can be called directly outside the class body.

**********************************************************************************************/
#include <iostream>
using namespace std;

class Base
{
public:
	virtual void print()
	{
		cout << "Printing from Base" << endl;
	}
};

class Derived : public Base
{
private:
	void print()
	{
		cout << "Printing from Derived" << endl;
	}
};

int main()
{
	Base *baseptr = new Derived();
	baseptr->print();
	return 0;
}
