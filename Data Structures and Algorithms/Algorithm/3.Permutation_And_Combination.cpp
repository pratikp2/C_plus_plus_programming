#include<iostream>
#include<vector>

std::vector<std::vector<int>> PermuteHolder;
std::vector<std::vector<int>> CombineHolder;

void FindPermutations(std::vector<int>& SampleSet, int index)
{
	if (index == SampleSet.size())
	{
		PermuteHolder.push_back(SampleSet);
		return;
	}

	for (int i = index; i < SampleSet.size(); i++)
	{
		std::swap(SampleSet[i], SampleSet[index]);
		FindPermutations(SampleSet, index + 1);
		std::swap(SampleSet[i], SampleSet[index]);
	}

	// Time Complexiry will be 
	// O(Single Permutations) * Total Permutations
	// i,e. O(1) * n
	// O(n) - Constant time.
}

void FindCombinations(std::vector<int> SampleSet, std::vector<int> subset, int index)
{
	if (index == SampleSet.size())
	{
		CombineHolder.push_back(subset);
		return;
	}
	else
	{
		FindCombinations(SampleSet, subset, index + 1);
		subset.push_back(SampleSet[index]);
		FindCombinations(SampleSet, subset, index + 1);
	}

	// Time Complexiry will be 
	// O(Single Permutations) * Total Permutations
	// i,e. O(1) * n
	// O(n) - Constant time.
}

void print()
{
	std::cout << "Permutations for given Sequence : " << std::endl;
	for (int i = 0; i < PermuteHolder.size(); i++)
	{
		std::cout << "[";

		for (int j = 0; j < PermuteHolder[i].size(); j++)
			std::cout << PermuteHolder[i][j] << " ";

		std::cout << "]" << std::endl;
	}

	std::cout << std::endl << std::endl;

	std::cout << "Combinations for given Sequence : " << std::endl;
	for (int i = 0; i < CombineHolder.size(); i++)
	{
		std::cout << "[ ";

		for (int j = 0; j < CombineHolder[i].size(); j++)
			std::cout << CombineHolder[i][j] << " ";

		std::cout << "]" << std::endl;
	}
}

int main()
{
	std::vector<int> vec{ 1,2,3 };
	std::vector<int> vec1;

	FindPermutations(vec, 0);
	FindCombinations(vec, vec1, 0);

	print();

	return 0;
}

// ****************************************** PERMUTATION : **************************************************
// A permutation is an act of arranging the objects or numbers in order.
// For a number of set 1,2,3 Different permutations would be as follows.
// (1,2,3) (1,3,2)
// (2,1,3) (2,3,1)
// (3,1,2) (3,2,1)
// Hence for given series there are 6 different arrangement i.e, Permutations.
//
// 
//	Calculate All Permutation via swapping Technique :
//  Consider the string "ABCD" for which we want to calculate all possible permutations. So all possible 
//  permutations will be calculated via following tree.
// 
//  LEVEL 1	|						  _________________________________________________________________ ABCD ____________________________________________________________________________
//			|						 | 													 | 												 |												 |
//			|						A-A												    A-B												A-C												A-D		
//			|						 |												     |												 |												 |
//	LEVEL 2	|		   ____________	ABCD ____________				   ________________ BACD ____________								CBAD											DBCA
//			|		  |				 |				 |				  |					 |				 |
//			|		 B-B			B-C				B-D				 A-A				A-C				A-D
//			|		  |				 |				 |				  |					 |				 |
//  LEVEL 3	|	  _	ABCD _		  _	ACBD _		  _ ADCB _		   _ BACD _		      _ BCAD _		  _ BDCA _
//			|	 |		 |		 |		  |		 |		  |		  |		   |		 |		  |		 |		  |		  
//			|	C-C		C-D		B_B		 B-D	C-C		C-B		 C-C	  C-D		A-A		A-D		C-C		C-A		
//			|	 |		 |		 |		  |		 |		  |		  |		   |		 |		  |		 |		  |
//  LEVEL 4	|	ABCD	ABDC	ACBD	ACDB	ADCB	ADBC	BACD	  BADC	   BCAD		BCDA	BDCA	BDAC
// 
// 
//	All the combination can be retrived via swapping one character at a time. For Example for LEVEL 1 we 
//	swapped 1st character with 2nd, 3rd and 4th positions got new strings.
//	Now in LEVEL 2, 1st position is already swapped so we swap 2nd position with 3rd and 4th position
//	and get new string.
//	Simiarly at LEVEL 3, as 1st and 2nd positions are already swapped, we swap 3rd position with 4th position
//	and got remaining strings.
//  Now at LEVEL 4 as 1st, 2nd and 3rd positions are already swapped so we can not swap 4th position with any 
//	other position. Hence this way we got all the possible permutation with this swapping algorithm. 
//	In Algorithm there are two swaps 1st swap is to get different premutation and second swap is for 
//	backtracking string to original permutation in order to swap other position and get different permutation.
// e.g, LEVEL 3  -> ACBD
//		LEVEL 4  -> ACDB (swapped)
//		Level 3  -> ACBD (Reverse swap to go to ABCD and swap different positions)


//
// ****************************************** COMBINATION : *************************************************
// Combinations are the way of selecting the objects or numbers from a group of objects or collection,
// in such a way that the order of the objects does not matter.
// For a number of set 1, 2, 3 combination of any two numbers would be as follows.
// (), (1), (2), (3), (12), (23) (13), (123) 
// the total number of arrangement would bw 2^(Number of positions)
//
// For Example the to find all combinatins or all possible subsets of the array {1,2,3} tree would be
//
//				  _________________	{} __________________
//				 |										 |								Adding 1 to 1st subset and skipping other 
//		 _______ {} _____					  _________ {1} ________
//		|				 |					 |						|					Adding 2 to 1st subset and skipping other 
//	 ___{} __		  _ {2} __			  _	{1}	__			   __ {1,2} ___
//	|		 |		 |		  |			 |		  |			  |			   |			Adding 3 to 1st subset and skipping other 
//	{}		{3}		{2}		{2,3}		{1}		{1,3}		{1,2}		{1,2,3}
//
//  Hence all the the subsets from empty subset () to subset containing all elements (1,2,3) are possible combinations for given sequence.