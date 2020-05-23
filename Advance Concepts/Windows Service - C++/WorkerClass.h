#pragma once
#include<iostream>
#include<fstream>
#include<windows.h>

class WorkerClass
{
private:
	static std::string defaultPath;
	static bool checkForDirectory();

public:
	static void writeToFile();
};

bool WorkerClass::checkForDirectory()
{
	defaultPath = "D:/Practice/Git_Repos/C++ Programming/Utils";

	DWORD ftyp = GetFileAttributesA(defaultPath.c_str());
	if (ftyp == INVALID_FILE_ATTRIBUTES)
		return false;  //something is wrong with your path!

	if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
		return true;   // this is a directory!

	return false;    // this is not a directory!
}

void WorkerClass::writeToFile()
{
	if (checkForDirectory())
		defaultPath = defaultPath + "/DATA1_FILE.txt";
	else
		defaultPath = "C:/Utils/DATA1_FILE.txt";

	{
		std::ofstream DATA_FILE;
		DATA_FILE.open(defaultPath, std::ios::out);
		DATA_FILE << "Checking Service Functionality" << std::endl;
		DATA_FILE.close();
	}
}