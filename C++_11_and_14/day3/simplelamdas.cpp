#include <iostream>
using namespace std;

void main(){
	
	auto lambda1 = []{cout << "Hello C++11" << endl;};
	lambda1();
	
	auto lambda2 = [](int num){cout << num << endl;};
	lambda2(10);
	
	auto lambda3 = [](int num, int& num2){cout << num << endl; num2++;};
	int num = 20;
	lambda3(10, num);
	cout << num << endl;
	
	auto lambda4 = [](int num){return num++;};
	int res = lambda4(5);
	cout << "Result of lambda4: " << res << endl; 

	auto lambda5 = [](int num)->int{return num++;};
	int res2 = lambda5(20);
	cout << "Result of lambda5: " << res2 << endl; 
}
