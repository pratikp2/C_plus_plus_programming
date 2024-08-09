#pragma once
#include "stdafx.h"


class Value
{
	std::string strValue;
public:
	Value();
	~Value() {}
	std::string get() const;
	void set(std::string val);
};

class Test1
{
protected:
public:

	const char * ptr = nullptr;
	Test1();
	~Test1();
	std::string get() const;
};

class Test2
{
	int value = 0;
	Value* ptrValue = nullptr;
public:
	Test2();
	Test2(const Test2& val);
	Test2* operator =(const Test2& val);
	std::string get() const;
	~Test2();
};



class Layer1
{
	Test1* ptrLayer1 = nullptr;
public:
	Layer1();
	~Layer1();
	void TestFunctionfromLayer1();
};

class Layer2 : public Layer1
{
	Test2* ptrLayer2 = nullptr;
public:
	Layer2();
	~Layer2();
	void TestFunctionfromLayer2();
};

class InfoBase : public Layer2
{
	const char * ptrInfoBase = nullptr;
public:
	InfoBase();
	~InfoBase();
	void TestFunctionfromInfoBase();
};

class Info : public InfoBase
{
	const int EncoderVersion = 58;
	std::vector<std::string> filenames;
	std::unique_ptr<Test1> ptrTest1;
	Test2* ptrTest2 = nullptr;

public:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int DecoderVersion)
	{
		if (DecoderVersion == EncoderVersion)
		{
			ar & filenames;
		}
		else
		{
			std::cout << " Error Occured....! Version Mismatch " << std::endl;
			std::cout << " Serialization Version	: " << EncoderVersion << std::endl;
			std::cout << " De-Serialization Version : " << DecoderVersion << std::endl;
		}
	}

	Info();
	Info(const Info& val);
	~Info();

	void PrintUniquePtr() const;
	void AddFilename(const std::string& filename);
	void Print() const;
};

BOOST_CLASS_VERSION(Info, 58);


