#include <iostream>
#include <memory>
using namespace std;

void setPtr(unique_ptr<int>& ptr){}

unique_ptr<int> getPtr(){
	auto ptr = make_unique<int>(10);
	return ptr;
}

void main(){
	auto up = make_unique<int>(10);
	//auto up2 = up;
	unique_ptr<int> up2;
	cout << up2.get() << endl;
	
	up2.reset(up.release());
	cout <<"up2: " << up2.get() << endl;
	
	auto up3 = std::move(up2);
	cout <<"up2: " << up2.get() << endl;
	
	setPtr(up3);
	
	up3.reset();
	cout << "up3: " << up3.get() << endl;
	
	auto up4 = getPtr();
}
