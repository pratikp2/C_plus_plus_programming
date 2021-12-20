#include <iostream>
using namespace std;

void FuncSig(int a) {}
void FuncSig(int a, int b) {}
// Function Overloading allowed only when function name is smame and arguments are different.

int FuncSig1() {return 10;}
//float FuncSig1(){return 10.5;}-> Function Overloading does not happen with differnent return type of Function.
//static int FuncSig1() {} 		-> Function Overloading does not happen when storage class of return type is differernt

void FuncSig2(int * ptr) {}
//void FuncSig2(int ptr []) {}	-> Function Overloading does not happen because both function accepts same arg 

//void FuncSig3(&FuncSig1) {}
//void FuncSig3(int (*fptr)()){}-> Function Overloading does not happen because both args call same function

void FuncSig4(int a) {}
//void FuncSig4(const int a) {}	-> Function Overloading does not happen just because const variable is pass to function.

void FuncSig5(int a){}
//void FuncSig5(int a = 0) {}	-> Function Overloading does not happen just because default arg is different.
 
void FuncSig6(unsigned int a)
{cout << "From FunctionSIG3 (unsigned int)"<< endl;}
void FuncSig6(signed int a) 
{cout << "From FunctionSIG3 (signed int)"<< endl;} 	// Always Call Signed Version first otherwise calls unsignesd version
void FuncSig6(float a) 
{cout << "From FunctionSIG3 (float)"<< endl;}		// Compiler Allows only with proper function call as called below
void FuncSig6(long long a)
{cout << "From FunctionSIG3 (long)"<< endl;}		// Compiler allows but always calls signed version. 


int main()
{
	FuncSig6(-3);
	FuncSig6(3);
	FuncSig6(3.5f);			// Mention as float explicitly in argument other wise function call will be ambigious with double.
	FuncSig6(123456789);
	return 0;
}

