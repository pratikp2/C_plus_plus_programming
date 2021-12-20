#include <iostream>
#include <windows.h>
#include <Shlwapi.h>
#include <string>
#include <filesystem>
#include <vector>
#include <chrono>
#include <iomanip>
#include <time.h>
#include <fstream>

#pragma comment(lib, "shlwapi.lib")
using namespace std::filesystem;
using namespace std::chrono_literals;

struct FileMetadata
{
	std::string relativePath = "";
	std::string type = "";
	int files = 0;
	int directories = 0;
	int bytes;
	std::string lastModifiesAt = "";
	std::string indentation = "";
};

std::string GetAssemblyExecutionPath();
const std::string AssemblyPath = GetAssemblyExecutionPath();

int GetFileSize(std::string filename)
{
	int tmp = std::filesystem::file_size(filename);
	std::ifstream in(filename.c_str(), std::ifstream::ate | std::ifstream::binary);
	return in.tellg();
}

int GetDirectorySize(std::string filename, int size)
{
	WIN32_FIND_DATAA data;
	HANDLE sh = NULL;
	int dirSize = size;
	sh = FindFirstFileA((filename + "\\*").c_str(), &data);

	if (sh == INVALID_HANDLE_VALUE)
		return 0;

	do
	{
		if (std::string(data.cFileName).compare(".") != 0 && std::string(data.cFileName).compare("..") != 0)
		{
			if ((data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY)
				dirSize = dirSize + GetDirectorySize(filename + "\\" + data.cFileName, dirSize);
			else
				dirSize += (__int64)(data.nFileSizeHigh * (MAXDWORD)+data.nFileSizeLow);
		}

	} while (FindNextFileA(sh, &data));

	return dirSize;
}

std::string GetAssemblyExecutionPath()
{
	TCHAR dest[MAX_PATH];
	DWORD length = GetModuleFileName(NULL, dest, MAX_PATH);
	PathRemoveFileSpec(dest);

	std::wstring filepath = dest;
	return std::string(filepath.begin(), filepath.end());;
}

std::string GetLastModifiedTime(std::string FilePath)
{
	std::string lastModifiedTime = "";
	struct stat result;
	if (stat(FilePath.c_str(), &result) == 0)
	{
		auto mod_time = result.st_mtime;
		struct tm tmp;
		gmtime_s(&tmp, &mod_time);

		lastModifiedTime = std::to_string(tmp.tm_year) + '-' + std::to_string(tmp.tm_mon) + '-' + std::to_string(tmp.tm_mday) + " " +
			std::to_string(tmp.tm_hour) + ':' + std::to_string(tmp.tm_min) + ':' + std::to_string(tmp.tm_sec);
	}

	return lastModifiedTime;
}

void DisplayDataSet(FileMetadata metadata)
{
	std::cout << metadata.indentation << "Path: " << metadata.relativePath << std::endl;
	std::cout << metadata.indentation << "Type: " << metadata.type << std::endl;

	if (metadata.type == "Directory")
	{
		std::cout << metadata.indentation << "Files: " << metadata.files << std::endl;
		std::cout << metadata.indentation << "Directories : " << metadata.directories << std::endl;
	}

	std::cout << metadata.indentation << "Bytes: " << (int)metadata.bytes << std::endl;
	std::cout << metadata.indentation << "Last Modifies At: " << metadata.lastModifiesAt << std::endl;

	std::cout << std::endl;
}

void GetFileListFromDirectory(std::string filepath, std::vector<std::string>& FileHolder, std::vector<std::string>& DirectoryHolder)
{
	for (const auto& entry : std::filesystem::directory_iterator(filepath))
	{
		if (std::filesystem::is_directory(entry.path()))
			DirectoryHolder.push_back(entry.path().string());
		else
			FileHolder.push_back(entry.path().string());
	}
}

void DisplayFileData(std::string filepath, std::string indentation)
{
	FileMetadata metadata;
	std::vector<std::string> FileHolder;
	std::vector<std::string> DirectoryHolder;

	// Read Files from Respective Directory
	GetFileListFromDirectory(filepath, FileHolder, DirectoryHolder);


	// Populate Metadata Structure for Respective Directory and Display Information
	if (filepath != AssemblyPath)
	{
		metadata.indentation = indentation + "\t";
		metadata.relativePath = filepath.substr(AssemblyPath.size() - 1, filepath.size() - 1);
	}
	else
	{
		metadata.relativePath = '.';
		metadata.indentation = indentation;
	}

	metadata.type = "Directory";
	metadata.bytes = (int)GetDirectorySize(filepath, 0);
	metadata.directories = DirectoryHolder.size();
	metadata.files = FileHolder.size();
	metadata.lastModifiesAt = GetLastModifiedTime(filepath);
	DisplayDataSet(metadata);

	// Display File Data
	for (int i = 0; i < FileHolder.size(); i++)
	{
		FileMetadata fileMetadata;
		fileMetadata.relativePath = FileHolder[i].substr(AssemblyPath.size(), filepath.size() - 1);
		fileMetadata.type = "File";
		fileMetadata.bytes = (int)GetFileSize(FileHolder[i]);
		fileMetadata.lastModifiesAt = GetLastModifiedTime(FileHolder[i]);
		fileMetadata.indentation = metadata.indentation + "\t";
		DisplayDataSet(fileMetadata);
	}

	// Display Directory Data by calling DisplayFileData recursively
	for (int i = 0; i < DirectoryHolder.size(); i++)
		DisplayFileData(DirectoryHolder[i], metadata.indentation);
}

int main()
{

	DisplayFileData(AssemblyPath, "");
	system("Pause");
	return 0;
}