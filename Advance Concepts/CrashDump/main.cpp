#include <Windows.h>
#include <iostream>
#include <signal.h>
#include <DbgHelp.h>
#include <tchar.h>
#include <strsafe.h>
#include <memory>
#include <thread>

#define MAXIMUM_PATH_SIZE	250

static void SignalHandler(int iID)
{
	std::cout<<"ID: "<<iID<<std::endl;
}

void RegisterSignals()
{
	signal(SIGINT, SignalHandler);
	signal(SIGILL, SignalHandler);
	signal(SIGFPE, SignalHandler);
	signal(SIGSEGV, SignalHandler);
	signal(SIGTERM, SignalHandler);
	signal(SIGBREAK, SignalHandler);
	signal(SIGABRT, SignalHandler);
}

int GenerateCrashDumpFile(EXCEPTION_POINTERS* pExcptr)
{
	MINIDUMP_EXCEPTION_INFORMATION ExpInfo;
	HANDLE hDumpFile;
	DWORD dwBufferSize = MAXIMUM_PATH_SIZE;
	WCHAR szPath[MAXIMUM_PATH_SIZE];
	WCHAR* pszMyApplicationName = L"MyApplication";

	WCHAR szFileName[MAXIMUM_PATH_SIZE];

	if(MessageBox(NULL, _T("Do you want to save the Dump File ? "), _T("Save Dialog"), MB_YESNO) == IDYES)
	{
		GetTempPath(MAXIMUM_PATH_SIZE, szPath);			// Generate crash in temp folder
		//WCHAR* szPath = L"D:\\Practice\\Git_Repos\\C++ Programming\\Advance Concepts\\Crash Dump Generation";

		StringCchPrintf(szFileName, MAXIMUM_PATH_SIZE, L"%s%s", szPath, pszMyApplicationName);

		CreateDirectory(szFileName, NULL);

		StringCchPrintf(szFileName, MAXIMUM_PATH_SIZE, L"%s%s\\%s.dmp", szPath, pszMyApplicationName, L"MyCrashDumpFile");

		//Get Handle to Dump File
		hDumpFile = CreateFile(szFileName, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_WRITE | FILE_SHARE_READ, 0, CREATE_ALWAYS, 0, 0);

		ExpInfo.ThreadId = GetCurrentThreadId();
		ExpInfo.ExceptionPointers = pExcptr;
		ExpInfo.ClientPointers = TRUE;

		bool bSuccessful = MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), hDumpFile, MiniDumpWithDataSegs, &ExpInfo, NULL, NULL );
	}
	return EXCEPTION_EXECUTE_HANDLER;
}

void method()
{
	Sleep(1);
}

int main()
{
	static std::unique_ptr<std::thread> SampleThread1;
	SampleThread1.reset(new std::thread(method));
	//SampleThread1->join();
	//SampleThread1->detach();

	RegisterSignals();

	__try {
		//int* pBadPtr;
		//*pBadPtr = 0;
	}
	__except (GenerateCrashDumpFile(GetExceptionInformation()))
	{
	}

	return 0;
}