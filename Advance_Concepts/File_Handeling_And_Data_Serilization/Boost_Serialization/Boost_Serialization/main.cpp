/** ************************************************************** Boost Setup for Visual Studios *******************************************************************

1. Inside property Manager in project property add a new property inside "Release | x64" named "Boost_Release_x64" and open it.
2. Inside section C/C++ in "Additional Include directories" add path up to boost in side boost_version.
3. Inside section Linker in "Additional Library directories" add path up to "boost_veriosn/stage/x64/lib"
4. Now outside Change Solution configuratiosn to "Release" and Solution Platforms to x64 and compile.

********************************************************************************************************************************************************************/

#include <iostream>
#include <vector>  
#include <fstream>   
#include <boost/serialization/vector.hpp>   
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/binary_object.hpp>


class Info
{
private:
	// Allow serialization to access non-public data members.  
	friend class boost::serialization::access;

	//template<class Archive>
	//void save(Archive & ar, const unsigned int version) const { ar & filenames;}

	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) { ar & filenames; }

	std::vector<std::string> filenames;

public:
	void AddFilename(const std::string& filename);
	void Print() const;
};

void Info::Print() const { std::copy(filenames.begin(), filenames.end(), std::ostream_iterator<std::string>(std::cout, "\n")); }
void Info::AddFilename(const std::string& filename) { filenames.push_back(filename); }


int main(int argc, char** argv)
{
	std::vector<Info> infs;

	Info info1, info2;
	info1.AddFilename("ThisFile.txt");
	info2.AddFilename("ThatFile.txt");
	info2.AddFilename("OtherFile.txt");

	info2.AddFilename("ABC");
	info2.AddFilename("123");
	info2.AddFilename("XYZ");

	infs.push_back(info1);
	infs.push_back(info2);

	// Save filename data contained in Info object  
	{
		std::ofstream Obj_ofstream("data.dat", std::ios::binary);
		boost::archive::binary_oarchive op_archive(Obj_ofstream);
		op_archive << infs;
		//Obj_ofstream.close();
	}

	// Restore from saved data and print to verify contents  
	std::vector<Info> restored_info;
	{
		std::ifstream Obj_ifstream("data.dat", std::ios::binary);
		boost::archive::binary_iarchive ip_archive(Obj_ifstream);
		ip_archive >> restored_info;
		//Obj_ifstream.close();
	}

	std::vector<Info>::const_iterator it = restored_info.begin();
	for (; it != restored_info.end(); ++it)
	{
		Info info = *it;
		info.Print();
	}

	std::cout << "Testing : " << std::endl;
	system("PAUSE");
	return 0;
}