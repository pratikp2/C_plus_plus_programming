#include<iostream>

constexpr int add(int a, int b) { return a + b; }

int main(int argc, char** argv)
{
	// Example 1 : Return value of add will be calculated at runtime.
	int a, b;
	std::cin >> a >> b;
	std::cout << add(a, b) << std::endl;


	// Example 2 : Return value of add will be calculated at compile time as function is declared constexpr 
	std::cout << add(1, 2) << std::endl;

	return 0;
}


// Constant Expression (constexpr) :

// Using constexpr specifier itis possible to evaluate the value of a function or variable at runtime.
// constexpre will not be called every time. if value of dependent variables are unknown for a function or variable const exprwill not be called at compiletime.