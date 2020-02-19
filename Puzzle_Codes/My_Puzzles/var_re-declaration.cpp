# include <iostream>

int main()
{
	int i = 10;
	std :: cout << "I : " << i <<std :: endl;

	{
		int i = 20;
		std :: cout << "I : " << i <<std :: endl;
	}

	std :: cout << "I : " << i <<std :: endl;

// Compiler won't throw error because Re Declaration of the i sec time is in the loop
// hence "i" becomes the local var for the different scope.
//----------------------------------------------------------------------------------------------
    int a = 2;
	int b = 3;

	int I = a&b;
	std :: cout << "I : " << I << std :: endl;
	std :: cout << "& I : " << &I << std :: endl;
	std :: cout << "& A : " << &a << std :: endl;
	std :: cout << "& B : " << &b << std :: endl;

//----------------------------------------------------------------------------------------------

	std :: cout << "ANS : " << (a++)+(++b) << std :: endl;

//----------------------------------------------------------------------------------------------

	return 0;
}


