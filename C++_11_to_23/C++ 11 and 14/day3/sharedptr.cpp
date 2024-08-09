#include <iostream>
#include <string>
#include <memory>
using namespace std;

class String{
public:	
	String(const char* data):str(data){
		cout << __FUNCSIG__ << endl;
	}
	~String(){
		cout << __FUNCSIG__ << endl;
	}
private:
	string str;
};
void main(){
	shared_ptr<int> sp1{new int(10)};
	cout << "IntPtr value: " << *sp1 << endl;
	
	string* str = new string("C++11 training");
	shared_ptr<string> sp2{str};
	cout << "Length: " << sp2->length() << endl;
	
	//delete str;
	
	//shared_ptr<string> sp3 = make_shared<string>("C++11 trainig program");
	auto sp3 = make_shared<String>("C++11 trainig program");
	
	getchar();
}






