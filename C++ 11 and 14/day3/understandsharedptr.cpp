#include <iostream>
#include <string>
#include <memory>
#include <exception>
using namespace std;

class String{
public:	
	String(const char* data):str(data){
		cout << "Constructor for: " << str << endl;
	}
	~String(){
		cout << "Destructor for: " << str << endl;
	}
private:
	string str;
};

void processString(const char* data){
	//String* str = new String(data);
	auto str = make_shared<String>(data);
	
	//....
	throw exception();
	
}
//deleter
void closeMyFile(FILE* fp){
	fclose(fp);
	cout << "File closed successfully..." << endl;
}

void writeFile(){
	//FILE* fp = fopen("sample.txt", "w");
	//shared_ptr<FILE> ptr{fp, closeMyFile};
	//shared_ptr<FILE> ptr{fopen("sample.txt", "w"), closeMyFile};
	
	shared_ptr<FILE> ptr{fopen("sample.txt", "w"), [](FILE* fp){fclose(fp); cout << "Closed file from lambda" << endl;}};
	
	
	fputs("Sample data to test...", ptr.get());
	//....
	//...
	cout << "File writing successful" << endl;
}

void main(){
	auto ptr1 = make_shared<String>("C++11");
	{
		auto ptr2 = ptr1;
		auto ptr3 = make_shared<String>("New New New");
		ptr3 = ptr1;
		cout << "Reference counter for ptr1: " << ptr1.use_count() << endl;
	}
	cout << "Reference counter for ptr1: " << ptr1.use_count() << endl;

	try{
		processString("Secret key");
	}catch(exception e){
		cout << "Exception catched..." << endl;
	}

	writeFile();
	
	getchar();
}
