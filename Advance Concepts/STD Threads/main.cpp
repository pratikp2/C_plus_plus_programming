#include <iostream>
#include <memory>
#include <thread>
#include "SampleClass.h"

int main()
{
	static std::unique_ptr<std::thread> SampleThread1;
	//static std::unique_ptr<std::thread> SampleThread2;
	//static std::unique_ptr<std::thread> SampleThread3;

	SampleThread1.reset(new std::thread(SampleClass::Method1));
	//std::cout << SampleThread1->get_id();
	//SampleThread1->detach();

	std::thread t1(SampleClass::Method1);
	//t1.detach();

	return 0;
}
	