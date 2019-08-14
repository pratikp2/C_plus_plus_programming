#pragma once
#include "stdafx.h"

class Test3
{
private:
	int var1 = 0;
	std::string var2;
	double var3 = 0;

public:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{	
		ar & var1;
		ar & var2;
		ar & var3;
	}

	Test3();
	~Test3() {}
};

class Nested_Case
{
private:
	int var1 = 0;
	std::string var2;
	double var3 = 0;
	std::vector<Test3> testVect;

public:
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		ar & var1;
		ar & var2;
		ar & var3;
		ar & testVect;												// Serialization for Nested Classes.
	}
};

class FunctionSpilt_Case
{

};

class NonIntrusive_Case
{

};
