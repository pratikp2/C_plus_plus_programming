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
int * function4();
int & function5();
int & function6();

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

    int *ptr4 = function4();
    cout << "4. Value Stored in returned ptr	:	"<< *ptr4 << endl<<endl;

    int &ref1 = function5();
    cout << "5. Address in returned ref B is 	: 	"<< &ref1 << endl;
    cout << "5. Value in returned ref B is 		: 	"<< ref1 << endl<<endl;

    int &ref2 = function6();
    cout << "6. Address in returned ref B is 	: 	"<< &ref2 << endl;
    cout << "6. Value in returned ref B is 		: 	"<< ref2 << endl;

    return 0;
}

void function1 (int *ptr) { cout << "1. Value Stored in ptr is 		:	"<< *ptr << endl<<endl; }

void function2 (int &ref) {
    cout << "2. Address in Reference arg. is 	: 	"<< &ref << endl;
    cout << "2. Value in the Reference arg. is	: 	"<< ref << endl<<endl;
}

int * function3() { return ptr2; } // Returning address hold by pointer i.e pointer

int * function4() { return &b; }   // Returning address hold by reference i.e pointer

int & function5() { return b; }    // Returning variable hence  automatically reference will be taken

int & function6() { return *ptr2; } // Returning *ptr (address) i.e reference
