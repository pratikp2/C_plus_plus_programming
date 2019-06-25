#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Data{
public:
	Data(const char* d){
		data = make_shared<string>(d);
	}
	auto GetData(){
		weak_ptr<string> wp{data};
		return wp;
	}
private:
	shared_ptr<string> data;
};

void main(){
	auto sp = make_shared<int>(10);
	weak_ptr<int> wp{sp};
	
	//cout << "Value: " << *wp << endl;
	if(!wp.expired())
	{
		auto sp1 = wp.lock();
		cout << "Value: " << *sp1 << endl;
	}
	
	
	//Example use case:
	Data* ptr = new Data("Very secret information");
	//....
	auto ptrData = ptr->GetData();
	if(!ptrData.expired()){
		auto ptrToUse = ptrData.lock();
		cout << *ptrToUse << endl;
	}
	else
		cout << "Data pointer is not available" << endl;
	
	//....
	//....
	delete ptr;
	
	if(!ptrData.expired()){
		auto ptrToUse = ptrData.lock();
		cout << *ptrToUse << endl;
	}
	else
		cout << "Data pointer is not available" << endl;
	
}










