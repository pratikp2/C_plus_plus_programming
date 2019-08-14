#include "TestClasses.h"

Value::Value()
{
	strValue = "Test Std String";
}

std::string Value::get() const
{
	return strValue;
}

void Value::set(std::string value) 
{
	strValue = value;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Test1::Test1()
{
	ptr = "Test1";
}

Test1::~Test1()
{
	if (ptr)
	{
		//delete ptr;
		ptr = nullptr;
	}

}

std::string Test1::get() const
{
	return ptr;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Test2::Test2()
{
	value = 10;
	ptrValue = new Value();
}

Test2::Test2(const Test2 &val)
{
	value = val.value;
	ptrValue = new Value();
	ptrValue->set(val.get());
}

Test2::~Test2()
{
	if (ptrValue != nullptr)
	{
		delete ptrValue;
		ptrValue = nullptr;
	}
}

Test2* Test2::operator=(const Test2& val)
{
	value = val.value;
	if (ptrValue){ delete ptrValue; }
	ptrValue = new Value();
	ptrValue->set(val.get());
	return this;
}

std::string Test2::get() const
{
	return ptrValue->get();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Layer1::Layer1()
{
	ptrLayer1 = new Test1;
}

Layer1::~Layer1()
{
	if (ptrLayer1 != nullptr)
	{
		delete ptrLayer1;
		ptrLayer1 = nullptr;
	}
}

void Layer1::TestFunctionfromLayer1()
{
	std::cout << "Test Function from Layer 1 Called which has value " << ptrLayer1->ptr << std::endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Layer2::Layer2()
{
	ptrLayer2 = new Test2;
}

Layer2::~Layer2()
{
	if (ptrLayer2 != nullptr)
	{
		delete ptrLayer2;
		ptrLayer2 = nullptr;
	}
}

void Layer2::TestFunctionfromLayer2()
{
	std::cout << "Test Function from Layer 2 Called which has value " << ptrLayer2->get() << std::endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


InfoBase::InfoBase()
{
	ptrInfoBase = "Info Base";
}

InfoBase::~InfoBase()
{
	if (ptrInfoBase != nullptr)
	{
		//delete ptrInfoBase;
		ptrInfoBase = nullptr;
	}
}

void InfoBase::TestFunctionfromInfoBase()
{
	std::cout << "Test Function from " << ptrInfoBase << " Called" << std::endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Info::Info()
{
	ptrTest1 = std::make_unique<Test1>();
	ptrTest2 = new Test2();
}

Info::Info(const Info& val)
{
	filenames = val.filenames;
	ptrTest2 = new Test2();
	*ptrTest2 = *(val.ptrTest2);
}

Info::~Info()
{
	if(ptrTest2 != nullptr)
	{
		delete ptrTest2;
		ptrTest2 = nullptr;
	}
}

void Info::PrintUniquePtr() const
{
	std::cout << "\n Content of unique ptr: " << ptrTest1->ptr << "\n";
}

void Info::Print() const 
{ 
	std::copy(filenames.begin(), filenames.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
}

void Info::AddFilename(const std::string& filename)
{
	filenames.push_back(filename); 
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////