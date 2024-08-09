#include<iostream>

template <typename ... T>
auto sum(T ... t) { return (t + ...); }

template <typename ... T>
auto sub(T ... t) { return (t - ...); }

template <typename ... T>
auto mul(T ... t) { return (t * ...); }

template <typename ... T>
auto div(T ... t) { return (t / ...); }

template <typename ... T>
auto avg(T ... t) { return (t + ...) / sizeof...(t); }

int main()
{
	std::cout << "Sum : " << sum(1, 2, 3, 4, 5) << std::endl;
	std::cout << "Sub : " << sub(1.0, 2.0, 3.0, 4.0, 5.0) << std::endl;
	std::cout << "Mul : " << mul(1, 2, 3, 4, 5) << std::endl;
	std::cout << "Div : " << div(1.0, 2.0, 3.0, 4.0, 5.0) << std::endl;
	std::cout << "Avg : " << sum(1, 2, 3, 4, 5) << std::endl;
	return 0;
}

// Fold Expression :

// Fold expressions are often used we wanto work with more than one input template parameter
// Hence instead of using 
// 
// template <typename T1, typename T2>
// auto sum(T1 t1, T2 t2) { return (t1 + t2); }
// 
// template <typename T1, typename T2,typename T3>
// auto sum(T1 t1, T2 t2, T3 t3) { return (t1 + t2 + t3); }
// 
// We can simply use the sum method written above

// Fold Expressions can be expanded in both ways.
// that is return (... / t); or return (t / ...);

// We can also use variables with Fold expression 
// that is 
// int i;
// return (i + t + ...);

// op - any of the following 32 binary operators : +-*/ % ^&| = < > << >> += -= *= /= %= ^= &= |= <<= >>= == != <= >= && || , .* ->*.In a binary fold, both ops must be the same.
// pack - an expression that contains an unexpanded parameter pack and does not contain an operator with precedence lower than cast at the top level(formally, a cast - expression)
// init - an expression that does not contain an unexpanded parameter pack and does not contain an operator with precedence lower than cast at the top level(formally, a cast - expression)