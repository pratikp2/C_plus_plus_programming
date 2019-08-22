/** ************************************************************** Boost Setup for Visual Studios *******************************************************************

	1. Inside property Manager in project property add a new property inside "Release | x64" named "Boost_Release_x64" and open it.
	2. Inside section C/C++ in "Additional Include directories" add path up to boost in side boost_version.
	3. Inside section Linker in "Additional Library directories" add path up to "boost_veriosn/stage/x64/lib"
	4. Now outside Change Solution configuratiosn to "Release" and Solution Platforms to x64 and compile.

********************************************************************************************************************************************************************/

#include "serializationOption.h"

int main(int argc, char** argv)
{
	int choice = 0;

	std::cout << "Please Enter the Choice for the Way to Serialiaze the Data" << std::endl << std::endl;
	std::cout << "1. Binary file Format" << std::endl;
	std::cout << "2. Text file Format" << std::endl;
	std::cout << "3. xml file Format" << std::endl;
	std::cout << "4. json file Format" << std::endl;

	std::cout << "5. Quit " << std::endl << std::endl;


	while (choice != 5)
	{
		std::cout << "Your Input : ";
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			Serialize_Binary_Format();
			break;
		case 2:
			Serialize_Text_Format();
			break;
		case 3:
			Serialize_xml_Format();
			break;
		case 4:
			Serialize_json_Format();
			break;
		case 5:
			system("exit");
			break;
		default:
			std::cout << "Invalid Input, Please Select proper Input" << std::endl;
			break;
		}
	}

	return 0;
}
