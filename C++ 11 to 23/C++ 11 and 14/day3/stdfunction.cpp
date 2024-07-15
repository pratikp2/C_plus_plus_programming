#include <iostream>
#include <functional>
using namespace std;

int add(int num1, int num2){return num1+num2;}
int sub(int num1, int num2){return num1-num2;}

class mul{
public:
		int operator()(int n1, int n2){return n1 * n2;}
};

//int performOperation(int n1, int n2, int(*ptr)(int,int)){
int performOperation(int n1, int n2, std::function<int(int,int)> ptr){
	return ptr(n1, n2);
}

void main(){
	cout << "Addtion: " << performOperation(10, 20, add) << endl;
	cout << "Substraction: " << performOperation(10, 20, sub) << endl;
	cout << "Multiplication: " << performOperation(10, 20, mul()) << endl;
	int multi = 100;
	cout << "Division: " << performOperation(10,20, [multi](int n1, int n2){return multi/n2;});
}



