/* *****************************************************************************************************

void function1 (int *ptr);   
void function2 (int &ref);

int * function3();
int & function4();

*******************************************************************************************************/
# include <iostream>
using namespace std;

void function1 (int *ptr);      // Passing Pointer and use directly 
void function2 (int &ref);      // Passing Reference Variable and use diretly 

int * function3();
int & function4();

int a = 20;
int b = 40;

int *ptr1 = &a;
int *ptr2 = &b; 

int main ()
{
	
	cout << "Address of Reference A is 		:	"<< &a << endl;
	cout << "Address of Reference B is 		:	"<< &b << endl<<endl;	

	function1(ptr1);
	function2(a);
	
	int *ptr3 = function3();
	cout << "3. Value Stored in returned ptr	:	"<< *ptr3 << endl<<endl;

	int &ref = function4();
	cout << "4. Address in returned ref B is 	: 	"<< &ref << endl;
	cout << "4. Value in returned ref B is 		: 	"<< ref << endl;

	return 0;
}

void function1 (int *ptr)
{
	cout << "1. Value Stored in ptr is 		:	"<< *ptr << endl<<endl;
}

void function2 (int &ref)
{
	cout << "2. Address in Reference arg. is 	: 	"<< &ref << endl;
	cout << "2. Value in the Reference arg. is	: 	"<< ref << endl<<endl;
}

int * function3()
{
	return ptr2;	
}

int & function4()
{
	return b;
}
