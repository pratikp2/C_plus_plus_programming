#include<iostream>
#include<algorithm>
#include<vector>


int main()
{	
	// Variable Collection
	std::vector<int> vecSample{ 3,5,9,8,7,1,3,6 };
	std::string stringSample = "ABC";
	char charSample = 'A';

	// 1. Sort Function
	std::sort(vecSample.begin(), vecSample.end());

	// 2. Reverse Function
	std::reverse(vecSample.begin(), vecSample.end());

	// 3. Find Function
	auto itr1 = std::find(vecSample.begin(), vecSample.end(), 2);

	// 4. Find Maximum
	auto itr2 = std::max_element(vecSample.begin(), vecSample.end());

	// 4. Find Minimum
	auto itr3 = std::min_element(vecSample.begin(), vecSample.end());

	// 5. Find if given charater is alphanumeric or not 
	bool status = isalnum(charSample);

	// 6. Find if given character is Alphabet or not.
	bool status1 = isalpha('A');

	// 7. Find is given character is digit or not.
	bool status2 = isdigit('8');

	// 8. Find all permutaions of given data .
	std::sort(stringSample.begin(), stringSample.end());
	do {
		std::cout << stringSample << '\n';
	} while (std::next_permutation(stringSample.begin(), stringSample.end()));
}