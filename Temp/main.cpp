#include <iostream>
#include <cstring>
#include <string>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;
using namespace std::chrono;


bool checkValidity(string s)
{
	for (int a = 0; a < s.size(); a++)
		if (int(s[a]) < 48 || int(s[a]) > 57)
			throw(false);
	return true;
}

bool isIPv4Address(std::string inputString)
{
	int start = 0, end = 0, sub = 0, count = 0;
	string s = "";

	for (auto temp : inputString)
		if (temp == '.')
			count++;
	if (count != 3)
		return false;

	inputString = "." + inputString + ".";

	for (int i = 0; i < 4; i++)
	{
		start = end;
		end = inputString.find(".", start + 1);
		try {
			s = inputString.substr(start + 1, end - start - 1);
			checkValidity(s);
			sub = stoi(s);
		}
		catch (...) {
			return false;
		}
		if (sub > 255)
			return false;
	}
	return true;
}


int main()
{
	auto start = high_resolution_clock::now();

	cout << isIPv4Address("0.245.255.0") << endl;

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

	system("pause");
	return 0;
}
