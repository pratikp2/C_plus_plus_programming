#pragma once

#include <iostream>
#include <vector>  
#include <fstream>   
#include <string>
#include <memory>
#include <boost/serialization/vector.hpp>   
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/binary_object.hpp>
#include <boost/serialization/version.hpp>


class Value
{
	std::string strValue;
public:
	Value() { strValue = "Test Std String"; }
	std::string get() const { return strValue; }
	void set(std::string val) { strValue = val; }
	~Value() {}
};

class Test1
{
public:
	const char * ptr = "Test 1";
};

class Test2
{
	int value;
	Value* ptrValue;
public:
	Test2()
	{
		value = 10;
		ptrValue = new Value();
	}
	Test2(const Test2& val)
	{
		value = val.value;
		ptrValue = new Value();
		ptrValue->set(val.get());
	}
	Test2* operator =(const Test2& val)
	{
		value = val.value;
		if (ptrValue)
		{
			delete ptrValue;
			ptrValue = nullptr;
		}
		ptrValue = new Value();
		ptrValue->set(val.get());
		return this;
	}
	std::string get() const { return ptrValue->get(); }
	~Test2() { delete ptrValue; }
};



class Layer1
{
	Test1* ptrLayer1;
public:
	Layer1() { ptrLayer1 = new Test1; }
	~Layer1()
	{
		delete ptrLayer1;
	}
	void TestFunctionfromLayer1() { std::cout << "Test Function from Layer 1 Called which has value " << ptrLayer1->ptr << std::endl; }
};

class Layer2 : public Layer1
{
	Test2* ptrLayer2;
public:
	Layer2() { ptrLayer2 = new Test2; }
	~Layer2()
	{
		delete ptrLayer2;
	}
	void TestFunctionfromLayer2() { std::cout << "Test Function from Layer 2 Called which has value " << ptrLayer2->get() << std::endl; }
};

class InfoBase : public Layer2
{
	const char * ptrInfoBase = "Info Base";
public:
	void TestFunctionfromInfoBase() { std::cout << "Test Function from " << ptrInfoBase << " Called" << std::endl; }
};
