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
	Nested_Case();
	~Nested_Case() {};
	void printData();

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
private:
	int var1 = 0;
	std::string var2;
	double var3 = 0;

public:
	FunctionSpilt_Case();
	~FunctionSpilt_Case() {}

	friend class boost::serialization::access;
	BOOST_SERIALIZATION_SPLIT_MEMBER()

	template<class Archive>
	void save(Archive & ar, const unsigned int version)
	{
		ar & var1;
		ar & var2;
		ar & var3;
	}

	template<class Archive>
	void load(Archive & ar, const unsigned int version)
	{
		ar & var1;
		ar & var2;
		ar & var3;
	}
};

class NonIntrusive_Case
{
private:
	int var1 = 0;
	std::string var2;
	double var3 = 0;

public:
	NonIntrusive_Case();
	~NonIntrusive_Case() {}
};

namespace boost
{
	namespace serialization
	{
		template<class Archive>
		void serialize(Archive & ar, NonIntrusive_Case & g, const unsigned int version)
		{
			ar & g.var1;
			ar & g.var2;
			ar & g.var3;
		}
	}
}