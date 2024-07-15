#include <iostream>
using namespace std;


void main(){
	int num1{5}, num2{3};
	
	auto add = [num1, num2](){return num1 + num2;};
	num1 = 100;
	cout << "Addition: " << add() << endl;
	
	int subRes;
	auto sub = [num1, num2, &subRes]{subRes = num1 - num2;};
	sub();
	cout << "Subtraction: " << subRes << endl;
	
	
	auto mul = [=]{return num1 * num2;};  //pass all the required variables by vale
	int resMul = mul();
	cout << "Multiplication: " << resMul << endl;
	
	float divRes;
	auto div = [&]{ divRes = (float)num1 / num2;};
	div();
	//divRes = -1;
	cout << "Division: " << divRes << endl;
	
	int resPower;
	auto power = [=, &resPower]{ resPower = pow(num1, num2);};
	power();
	cout << "Power: " << resPower << endl;
	
	int resMod;
	auto mod = [&, num1, num2]{resMod = num1 % num2;};
	mod();
	cout << "Modulus: " << resMod << endl;
	
}
