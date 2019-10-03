/** ********************************************************************************************************

		Attributes are one of the key features of modern C++ which allows the programmer to specify additional 
	information to the compiler to enforce constraints(conditions), optimise certain pieces of code or do
	some specific code generation. In simple terms, an attribute acts as an annotation or a note to the 
	compiler which provides additional information about the code for optimization purposes and enforcing
	certain conditions on it.

***********************************************************************************************************/


#include<iostream>
using namespace std;


[[depricated("The Function1 has been Depricated Please use Function 2")]]
void Function1(){cout << "Raised compiler warning for deprication" << endl;}

void Function2(){}

int main()
{
	cout << endl;
	
	Function2();
	return 0;
}	