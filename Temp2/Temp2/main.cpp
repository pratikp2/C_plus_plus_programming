#include <iostream>
#include <cstring>
#include <string>
#include <chrono> 

using namespace std;
using namespace std::chrono;

#define SIZE 10
#define TARGET 100
int CURRENTSUM = 0;
std::string ABC = "";

int RecursionBackTracking(int arr[], int index, int sum, string s)
{
	if (index > SIZE - 1 || sum == TARGET)
	{
		if (sum > CURRENTSUM && sum <= TARGET)
		{
			CURRENTSUM = sum;
			ABC = s;
		}
		else
			sum = CURRENTSUM;
		return sum;
	}
		
	int sum1 = RecursionBackTracking(arr, index + 1, sum, s);

	if (sum + arr[index] <= TARGET)
		sum = RecursionBackTracking(arr, index + 1, sum + arr[index], s + " " + to_string(arr[index]));

	sum = (sum > sum1) ? sum : sum1;

	cout << sum << " ";
	return sum;
}

int main()
{
	auto start = high_resolution_clock::now();
	int arr[SIZE] = {2,5,6,8};
	//int arr[SIZE] = {4,14,15,18,29,32,36,82,95,95};
	/*int arr[SIZE] = { 7, 12, 12, 13, 14, 28, 29, 29, 30, 32,
		32, 34, 41, 45, 46, 56, 61, 61, 62, 63,
		65, 68, 76, 77, 77, 92, 93, 94, 97, 103,
		113, 114, 114, 120, 135, 145, 145, 149, 156, 157,
		160, 169, 172, 179, 184, 185, 189, 194, 195, 195 };*/

	cout << RecursionBackTracking(arr, 0, 0, "") << endl;
	cout << "Ans : " << CURRENTSUM << endl;
	cout << "Ans : " << ABC << endl;

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;

	system("pause");
	return 0;
}
