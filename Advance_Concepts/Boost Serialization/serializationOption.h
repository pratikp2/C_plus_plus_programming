#pragma once
#include "UseCases.h"
#include "TestClasses.h"

std::vector<Info> FillVect()
{
	std::vector<Info> infs;

	Info info1;
	Info info2;

	info1.AddFilename("ThisFile.txt");
	info1.AddFilename("ThatFile.txt");
	info1.AddFilename("OtherFile.txt");

	info2.AddFilename("ABC");
	info2.AddFilename("123");
	info2.AddFilename("XYZ");

	infs.push_back(info1);
	infs.push_back(info2);

	return infs;
}

void PrintVect(std::vector<Info> restored_info)
{
	std::vector<Info>::const_iterator it = restored_info.begin();
	for (it = restored_info.begin(); it != restored_info.end(); ++it)
	{
		it->Print();
		it->PrintUniquePtr();
	}

	restored_info[0].TestFunctionfromInfoBase();
	restored_info[0].TestFunctionfromLayer1();
	restored_info[0].TestFunctionfromLayer2();

	restored_info[1].TestFunctionfromInfoBase();
	restored_info[1].TestFunctionfromLayer1();
	restored_info[1].TestFunctionfromLayer2();
}

void Serialize_Binary_Format()
{
	std::vector<Info> infs = FillVect();
	std::vector<Info> restored_info;

	{
		std::ofstream Obj_ofstream("data.bin", std::ios::binary);
		boost::archive::binary_oarchive op_archive(Obj_ofstream);
		op_archive << infs;
	}

	{
		std::ifstream Obj_ifstream("data.bin", std::ios::binary);
		boost::archive::binary_iarchive ip_archive(Obj_ifstream);
		ip_archive >> restored_info;
	}

	//PrintVect(restored_info);

	std::vector<Info>::const_iterator it = restored_info.begin();
	for (it = restored_info.begin(); it != restored_info.end(); ++it)
	{
		it->Print();
		it->PrintUniquePtr();
	}

	restored_info[0].TestFunctionfromInfoBase();
	restored_info[0].TestFunctionfromLayer1();
	restored_info[0].TestFunctionfromLayer2();

	restored_info[1].TestFunctionfromInfoBase();
	restored_info[1].TestFunctionfromLayer1();
	restored_info[1].TestFunctionfromLayer2();
}

void Serialize_Text_Format()
{
	std::vector<Info> infs = FillVect();
	std::vector<Info> restored_info;

	{
		std::ofstream Obj_ofstream("data.txt");
		boost::archive::text_oarchive op_archive(Obj_ofstream);
		op_archive << infs;
	}

	{
		std::ifstream Obj_ifstream("data.txt");
		boost::archive::text_iarchive ip_archive(Obj_ifstream);
		ip_archive >> restored_info;
	}

	//PrintVect(restored_info);

	std::vector<Info>::const_iterator it = restored_info.begin();
	for (it = restored_info.begin(); it != restored_info.end(); ++it)
	{
		it->Print();
		it->PrintUniquePtr();
	}

	restored_info[0].TestFunctionfromInfoBase();
	restored_info[0].TestFunctionfromLayer1();
	restored_info[0].TestFunctionfromLayer2();

	restored_info[1].TestFunctionfromInfoBase();
	restored_info[1].TestFunctionfromLayer1();
	restored_info[1].TestFunctionfromLayer2();
}

void Serialize_xml_Format()
{
	Nested_Case infs;
	Nested_Case restored_info;

	{
		std::ofstream Obj_ofstream("data.xml");
		boost::archive::xml_oarchive op_archive(Obj_ofstream);
		op_archive << infs;
	}

	{
		std::ifstream Obj_ifstream("data.xml");
		boost::archive::xml_iarchive ip_archive(Obj_ifstream);
		ip_archive >> restored_info;
	}

	for (it = restored_info.begin(); it != restored_info.end(); ++it)
	{
		it->Print();
		it->PrintUniquePtr();
	}



	restored_info[0].TestFunctionfromInfoBase();
	restored_info[0].TestFunctionfromLayer1();
	restored_info[0].TestFunctionfromLayer2();

	restored_info[1].TestFunctionfromInfoBase();
	restored_info[1].TestFunctionfromLayer1();
	restored_info[1].TestFunctionfromLayer2();
}

void Serialize_json_Format()
{

}

// ##########################################			serialize()			################################################################

// While serializing the standard data type you can define Save() and Load() Methods, and call them.

// In order to serialize objects of user-defined types, you must define the member function serialize(). This function is called when
// the object is serialized to or restored from a byte stream. Because serialize() is used for both serializing and restoring, 
// Boost.Serialization supports the operator operator& in addition to operator<< and operator>>. With operator& there is no need to 
// distinguish between serializing and restoring within serialize().

// serialize() is automatically called any time an object is serialized or restored.It should never be called explicitly and, thus,
// should be declared as private.If it is declared as private, the class boost::serialization::access must be declared as a friend 
// to allow Boost.Serialization to access the member function.

// More Info : https://theboostcpplibraries.com/boost.serialization-archive

// ##########################################			Versioning for Archive		##########################################################

// The macro BOOST_CLASS_VERSION assigns a version number to a class. If BOOST_CLASS_VERSION is not used, the version number is 0 by default.
// The version number is stored in the archive and is part of it.While the version number specified for a particular class via the BOOST_CLASS_VERSION
// macro is used during serialization, the parameter version of serialize() is set to the value stored in the archive when restoring.If the
// new version of animal accesses an archive containing an object serialized with the old version, the member variable name_ would not be 
// restored because the old version did not have such a member variable.

// ##############################################################################################################################################

/*#include <cstdlib>
#include <fstream>
#include <iostream>
#include "json/json.h"
int main(void) {
Json::Reader reader;
Json::Value root;
Json::StyledStreamWriter writer;
std::string text = "{ \"first\": \"James\", \"last\": \"Bond\", \"nums\": [0, 0, 7] }";
std::ofstream outFile;
// Parse JSON and print errors if needed
if (!reader.parse(text, root)) {
std::cout << reader.getFormattedErrorMessages();
exit(1);
}
else {
// Read and modify the json data
std::cout << "Size: " << root.size() << std::endl;
std::cout << "Contains nums? " << root.isMember("nums") << std::endl;
root["first"] = "Jimmy";
root["middle"] = "Danger";
// Write the output to a file
outFile.open("output.json");
writer.write(outFile, root);
outFile.close();
}
return 0;
}*/