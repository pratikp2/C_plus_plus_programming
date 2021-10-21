#include <list>
#include <cstring>
#include <iostream>
using namespace std;

class HashTable
{
private : 
	static const int m_HashGroup = 10;
	list <pair<int, string>> m_table[m_HashGroup];

public:
	bool IsEmpty() const;
	int HashFunction(int key);
	void InsertItem(int key, string value);
	void RemoveItem(int key);
	string SearchTable(int key);
	void PrintTable();
};

bool HashTable::IsEmpty() const
{
	int size = 0;
	for (int i = 0; i < m_HashGroup; i++)
		if (m_table[i].size() != 0)
			return false;

	return true;
}

int HashTable::HashFunction(int key)		// Ideally Complexity O(1) : Constant Time
{
	return key % m_HashGroup;				// for e,g. key 905 it will return 5 
}

void HashTable::InsertItem(int key, string value)	// Collision Not Handled ....!!!!
{
	auto& cell = m_table[HashFunction(key)];
	
	auto itr = begin(cell);
	bool keyExist = false;

	for (; itr != end(cell); itr++)
	{
		if (itr->first == key)
		{
			keyExist = true;
			itr->second = value;
			cout << "[WARNING] Key Exist. Value Replaced" << endl;
			break;
		}
	}

	if (!keyExist)
		cell.emplace_back(key, value);
}

void HashTable::RemoveItem(int key)
{
	auto& cell = m_table[HashFunction(key)];

	auto itr = begin(cell);
	bool keyExist = false;

	for (; itr != end(cell); itr++)
	{
		if (itr->first == key)
		{
			keyExist = true;
			itr = cell.erase(itr);
			cout << "[INFO] Item Removed." << endl;
			break;
		}
	}

	if (!keyExist)
		cout << "Item Not Found in the table ....!!!" << endl;
}

string HashTable::SearchTable(int key)
{
	auto& cell = m_table[HashFunction(key)];

	auto itr = begin(cell);
	bool keyExist = false;

	for (; itr != end(cell); itr++)
	{
		if (itr->first == key)
		{
			keyExist = true;
			cout << "[INFO] Key found." << endl;
			return itr->second;
		}
	}

	if (!keyExist)
		cout << "Item Not Found in the table ....!!!" << endl;

	return "[WARNING] Respective Key not found ...!!!";
}

void HashTable::PrintTable()
{
	for (int i = 0; i < m_HashGroup; i++)
	{
		if (m_table[i].size() == 0)
			continue;

		auto itr = begin(m_table[i]);
		for (; itr != m_table[i].end(); itr++)
			cout << "[Info] Key	: " << itr->first << "	Value :	 " << itr->second << endl;
	}
	cout << endl;
}

int main()
{
	try
	{
		HashTable ht;

		if (ht.IsEmpty())
			cout << "Working Fine..!" << endl;
		else
			cout << "Something wrong with code" << endl;

		ht.InsertItem(905, "Jim");
		ht.InsertItem(925, "Gym");
		ht.InsertItem(908, "roby");
		ht.InsertItem(907, "sandy");
		ht.InsertItem(955, "ed");
		ht.InsertItem(955, "duplicate");
		ht.InsertItem(995, "Pratik");

		ht.PrintTable();

		ht.RemoveItem(905);
		ht.PrintTable();
	}
	catch (exception ex)
	{
		cout << "Exception caught during Program Execution : " << ex.what() << endl;
	}

	system("pause");
	return 0;
}


// Visual Representation 
//	Table
//	------------------------------------
//	|	Key		|	Value	|	Index	|
//	------------------------------------
//	------------------------------------
//	|	Paul	|	29		|	7		|
//	------------------------------------
//	|	Jane	|	35		|	1		|
//	------------------------------------
//	|	Chloe	|	88		|	2		|
//	------------------------------------
//	|	Alex	|	18		|	0		|
//	------------------------------------

// Presentation in Data structure
//
//		0			1			2			3			4			5			6			7
//	-------------------------------------------------------------------------------------------------
//	|	Alex	|	Jane	|	Chloe	|			|			|			|			|	Paul	|
//	|	18		|	35		|	88		|			|			|			|			|	29		|
//	-------------------------------------------------------------------------------------------------
//					|
//					↓
//				-------------
//				|	Jake	|
//				|	20		|
//				-------------

// Calculation for Placing data into specific Index
// for Paul	
//	p - a = 15 (ascii)
//	15 mod 8 = 7 
//	hence 7th index for Paul
//	Above way of calculating index is called a hashing hence HashFunction 

//	Collision
// When two distinct entries comes up with same Index via Hashing Function then 
// the condition is called collision. There are different condition to avoid 
// or handle "Collision". e.g, Chaining.

// Chaining 
// When multiple data sets comes up with same index the instead of saving one data set 
// at that position store a linked list at that index which will store the multiple 
// data set in the list under the same index. for e,g. Jane and Jake at index 1.

