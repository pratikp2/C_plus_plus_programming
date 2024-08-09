#include<iostream>

int main(int argc, char** argv)
{
	int decimal = 42;
	int octal = 052;
	int hex = 0x2a;
	int heX = 0X2A;
	int binary = 0b101010; // C++14

	std::cout << decimal << std::endl;
	std::cout << octal << std::endl;
	std::cout << hex << std::endl;
	std::cout << heX << std::endl;
	std::cout << binary << std::endl;

	// operations on binary literals

	binary = binary * binary;
	std::cout << binary << std::endl;

	binary = binary / binary;
	std::cout << binary << std::endl;

	binary = binary + binary;
	std::cout << binary << std::endl;

	binary = binary - binary;
	std::cout << binary << std::endl;

	return 0;
}


// Types of Literal

// 1) Decimal integer literal(base 10)
// 2) Octal integer literal(base 8)
// 3) Hexadecimal integer literal(base 16, the letters 'a' through 'f' represent values(decimal) 10 through 15)
// 4) Binary integer literal(base 2) ---------------> (C++ 14 Feature)


// decimal - literal is a non - zero decimal digit(1, 2, 3, 4, 5, 6, 7, 8, 9), followed by zero or more decimal digits(0, 1, 2, 3, 4, 5, 6, 7, 8, 9)
// octal - literal is the digit zero(0) followed by zero or more octal digits(0, 1, 2, 3, 4, 5, 6, 7)
// hex - literal is the character sequence 0x or the character sequence 0X followed by one or more hexadecimal digits(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, a, A, b, B, c, C, d, D, e, E, f, F)
// binary - literal is the character sequence 0b or the character sequence 0B followed by one or more binary digits(0, 1)