#pragma once

#include <iostream>
#include <vector>  
#include <fstream>   
#include <boost/serialization/vector.hpp>   
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/binary_object.hpp>

class Test1 
{
public:
	const char * ptr = "Test 1";
};

class Test2
{
public:
	const char * ptr = "Test 2";
};



class Layer1
{
public:
	const char * ptr = "Layer 1";
	Test2 * m_ptrTest2;

	Layer1() { m_ptrTest2 = new Test2; }
	~Layer1()
	{
		delete m_ptrTest2;
		m_ptrTest2 = NULL;
	}
};

class Layer2 : public Layer1
{
public:
	const char * ptr = "Layer 2";
	void TestFunction21() { std::cout << "Test Function 1 Called" << std::endl; }
};

class Layer3 : public Layer2
{
public:
	const char * ptr = "Layer 3";
};
