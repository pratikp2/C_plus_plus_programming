#include <iostream>
#include <algorithm>
using namespace std;


void main(){
	
	//Stateless lamda
	auto lambda1 = []{cout << "Hello World!" << endl;};
	lambda1();
	
	
	//mutable lambda
	int num{10};
	auto lambda2 = [num]()mutable->int {num++;cout << "Num: " << num << endl;return -1;};
	lambda2();
	
	//generic lambda
	int num2{20};
	auto lambda3 = [](auto n1, auto n2){return n1 + n2;};
	int res = lambda3(num, num2);
	cout << "Result of auto lambda: " << res << endl;
	
	
	//lambda with stl algorithms
	int arr[] = {1,2,3,4,5};
	transform(cbegin(arr), cend(arr), begin(arr),[](int n){ return n*10;});
	for_each(cbegin(arr), cend(arr), [](int val){cout << val << "***";});
}
