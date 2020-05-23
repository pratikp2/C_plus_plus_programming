#include <iostream>
#include <memory>
#include <thread>
#include "SampleClass.h"

void Method()
{
	while (true);
}

int main()
{
	try
	{
		static std::unique_ptr<std::thread> SampleThread1;
		//static std::unique_ptr<std::thread> SampleThread2;
		//static std::unique_ptr<std::thread> SampleThread3;

		SampleThread1.reset(new std::thread(Method));
		//std::cout << SampleThread1->get_id();
		SampleThread1->detach();

		std::thread t1(Method);
		t1.detach();
		t1.join();
	}
	catch (const std::exception & ex)
	{
		std::cout << ex.what() << std::endl;
	}

	return 0;
}
	