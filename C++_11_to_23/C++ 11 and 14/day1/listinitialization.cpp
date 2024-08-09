#include <iostream>
using namespace std;

void TestFun(int, int);
class Test{
public:
	Test(){cout << __FUNCSIG__ << endl;}
	Test(int num){cout << __FUNCSIG__ << endl;}
};
void main()
{
	// Test obj1;
	// Test obj2(10);
	// Test obj3();		//Most vexing parse
	// Test  obj4 = Test();	
	
	Test obj1{};
	Test obj2{10};
	Test obj3{};		//Most vexing parse
	Test  obj4 = Test{};
}