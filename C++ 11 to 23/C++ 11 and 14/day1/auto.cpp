#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

constexpr long long factorial(int num){
	return num == 1 ? 1 : num * factorial(num-1);
}

constexpr bool someProcessing(int num){
	int counter = 0;
	while(counter++ < 2000)
		factorial(20);
	return true;
}

void printCurrentTime(){
	auto currTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
	cout<< ctime(&currTime) << endl;
	
}
const int someVar = 10;
void main()
{
	auto startTime = chrono::steady_clock::now();
	
	//long long result = factorial(20);
	auto result = someProcessing(20);
	
	auto endTime = chrono::steady_clock::now();
	
	//chrono::duration<int, std::micro> dur = chrono::duration_cast<chrono::duration<int, std::micro>> (endTime - startTime);
	auto dur = chrono::duration_cast<chrono::microseconds> (endTime - startTime);
	
	
	cout << "Execution Time: " << dur.count() << endl;
	//cout << "Factorial: " << result << endl;
	
	printCurrentTime();
	
}