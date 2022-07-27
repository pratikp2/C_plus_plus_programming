#include <iostream>
#include <stdio.h>
#include <vector>
#include <filesystem>
#include <fstream>
#include <unordered_set>
#include <set>
#include <chrono>
#include <thread>
#include <algorithm>
using namespace std;

#ifdef __linux__
/*
 LINUX specific
 GetFileLastWrite  get last file write time in UNIX epoch time
*/
#include <sys/stat.h>
#include <sys/types.h>

const std::string walFilePath = "/var/lib/postgresql/12/main/pg_wal";

double GetFileLastWrite(const string& filename)
{
	struct stat attr;
	stat(filename.c_str(), &attr);
	return (double)attr.st_mtim.tv_sec + attr.st_mtim.tv_nsec / (1000 * 1000 * 1000.0); //get time in seconds (UNIX) epoch
}
#endif

#ifdef WIN32
#include <Windows.h>
#define popen _popen
#define UNIXTOFILETIME_DIFF 11644473600LL

const std::string walFilePath = "";

double GetFileLastWrite(const string& filename)
{
	FILETIME ftCreate, ftAccess, ftWrite;
	HANDLE hFile = CreateFileA(filename.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
	GetFileTime(hFile, &ftCreate, &ftAccess, &ftWrite);
	CloseHandle(hFile);

	unsigned __int64 timeh = ftWrite.dwHighDateTime;
	unsigned __int64 timel = ftWrite.dwLowDateTime;
	timeh = (timeh << 32) + timel;

	double ret = timeh / (1000 * 1000 * 10.0); //FILE time uses 100nano second interval

	ret -= UNIXTOFILETIME_DIFF;
	return ret;
}
#endif

/*
 * GetWALFileNamesFromFolder will only populate files modified after lastbackuptime
 * //boost equivalent code :https://gist.github.com/vivithemage/9517678
*/

vector<std::filesystem::path> GetWALFileNamesFromFolder(std::filesystem::path foldername, double lastbackuptime = 0, const set<string>& ignorelist = set<string>())
{
	vector<std::filesystem::path> r;
	std::filesystem::recursive_directory_iterator it(foldername);

	for (auto file : it)
	{
		if (filesystem::is_directory(file) == false && ignorelist.find(file.path()) == ignorelist.end())
		{
			double lastfilewite = GetFileLastWrite(file.path());

			if (lastbackuptime <= lastfilewite)
				r.push_back(file);
			else
				cout << "ignored:" << file << endl << flush;
		}
	}
	return r;
}

void ExecuteCommandInPSQLShell(const string& command)
{
	FILE* fp = popen("psql postgres", "w");
	if (fp)
	{
		fprintf(fp, command.c_str());
		fclose(fp);
	}
}

void ZipAllFiles(const vector<std::filesystem::path>& files, const string& sZipFile)
{
	remove(sZipFile.c_str());

	stringstream ss;

	ss << "zip -o " << sZipFile << " ";
	for (auto file : files)
	{
		ss << file << " ";
	}
	cout << ss.str() << flush;
	system(ss.str().c_str());
}

void UnZip(const string& sZipFile)
{
	string sCommand = "unzip -o " + sZipFile;
	std::filesystem::current_path("/"); //setting path
	system(sCommand.c_str());
}

void CreateIgnoreListOfFiles(const unordered_set<string>& ignorelist, const string& filename)
{
	fstream fs(filename, ios::app);
	fs << ignorelist.size() << endl;

	for (auto i : ignorelist)
		fs << i << endl;
}

unordered_set<string> getIgnoreList(const string& filename)
{
	unordered_set<string> r;
	size_t sz = 0;
	fstream fs(filename, ios::in);
	fs >> sz; //get the list size
	for (size_t i = 0; i < sz; ++i)
	{
		string t;
		fs >> t;
		r.insert(t);
	}
	return r;
}

int main()
{
	//double currenttime=chrono::duration_cast<chrono::seconds>(chrono::system_clock::now().time_since_epoch()).count();
	ExecuteCommandInPSQLShell("select * from table_name");
	double lastbackupUNIXTIME = 1000;  //last back up took place at UNIX epoch time=1000

	auto fileList_BeforeSwitch = GetWALFileNamesFromFolder(walFilePath, lastbackupUNIXTIME);  //get all the files
	ExecuteCommandInPSQLShell("select pg_switch_wal()");
	auto fileList_AfterSwitch = GetWALFileNamesFromFolder(walFilePath, lastbackupUNIXTIME);  //get all the files

	if (fileList_BeforeSwitch.size() == fileList_AfterSwitch.size())
	{
		//new wal file is NOT created
		auto it = std::minmax(fileList_BeforeSwitch.begin(), fileList_BeforeSwitch.end());
		fileList_BeforeSwitch.erase(it.second); //delete the last file name, we will not back this one
	}

	ZipAllFiles(fileList_BeforeSwitch, "a.zip");

	auto p = std::filesystem::current_path();
	UnZip(p.generic_string() + "/a.zip");

	return 0;
}

//ExecuteCommandInPSQLShell("select pg_start_backup(\"label\",true)");
//ExecuteCommandInPSQLShell("select pg_switch_wal()");
//sleep(24 hrs);
//ExecuteCommandInPSQLShell("select pg_stop_backup()");
//CreateIgnoreListOfFiles({"asd","435435","sdf2","*&^"},"a.txt");
//CreateIgnoreListOfFiles({"asd","435435","sdf2","*&^"},"a.txt");
//auto ignorelist=getIgnoreList("a.txt");
