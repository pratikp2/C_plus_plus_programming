#include<iostream>

auto FunctionRTDeduction()
{
	return 10;
}

auto FunctionRTDeductionRecusion(int i)
{
	if (i <= 1)
		return i;

	--i;
	FunctionRTDeductionRecusion(i);
}

int main(int argc, char** argv)
{
	std::cout << FunctionRTDeduction();
	std::cout << std::endl;
	std::cout << FunctionRTDeductionRecusion(10);
	return 0;
}


// C++11 allowed lambda functions to deduce the return type based on the type of the expression given to the return statement.C++14 provides this ability to all functions.
// It also extends these facilities to lambda functions, allowing return type deduction for functions that are not of the form return expression;
// In order to induce return type deduction, the function must be declared with auto as the return type, but without the trailing return type specifier in C++11:

// If multiple return expressions are used in the function's implementation, then they must all deduce the same type.
// Functions that deduce their return types can be forward declared, but they cannot be used until they have been defined.Their definitions must be available to the translation unit that uses them.
// Recursion can be used with a function of this type, but the recursive call must happen after at least one return statement in the definition of the function : [4]