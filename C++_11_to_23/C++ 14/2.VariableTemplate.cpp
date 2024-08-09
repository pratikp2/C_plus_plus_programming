#include<iostream>

template<class T>
T pi = T(3.1415926535897932385L); // variable template

template<class T>
T circular_area(T r) // function template
{
	return pi<T> *r * r; // pi<T> is a variable template instantiation
}

int main(int argc, char** argv)
{
	pi<char> = 'a'; // Variable specialization similar to templete specialization

	std::cout << "int				: " << pi<int> << std::endl;
	std::cout << "float				: " << pi<float> << std::endl;
	std::cout << "double			: " << pi<double> << std::endl;
	std::cout << "long double		: " << pi<long double> << std::endl;
	std::cout << "char				: " << pi<char> << std::endl;

	return 0;
}


// Types of Templates 
// 1. Function Templates
// 2. Class Template
// 3. Variable Template (Since C++ 14) 

// A variable instantiated from a variable template is called an instantiated variable.
// A static data member instantiated from a static data member template is called an instantiated static data member.
// A variable template may be introduced by a template declaration at namespace scope, where variable - declaration declares a variable.
// With variable template there is no need to encapsulate variable with in function template just to get diffternt behaviour for variables.