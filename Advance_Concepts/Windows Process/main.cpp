#include <windows.h>
#include <string>
#include <iostream>
#include <wchar.h>

bool InvokeProcess(std::string&);

int main()
{
	std::string status = "";

	if (InvokeProcess(status))
		std::cout << "Process Execution Successful" << std::endl;
	else
		std::cout << "Process Execution Unsuccessful" << std::endl;

	return 0;
}

bool InvokeProcess(std::string& status)
{
	try
	{
		WCHAR ProgFilePath[23];
		ExpandEnvironmentStrings(L"%ProgramFiles(x86)%", ProgFilePath, 23);

		std::wstring ExePath, FilePath;
		ExePath = FilePath = std::wstring(ProgFilePath);
		ExePath = ExePath + L"\\Hewlett-Packard\\HP Touchpoint Manager\\Tools\\hpReport.exe";
		FilePath = FilePath + L"\\Hewlett-Packard\\HP Touchpoint Manager\\Tools";

		TCHAR Text[18] = L"hpReport.exe /get";
		LPWSTR lpCommandLine = (LPWSTR)Text;

		/* CreateProcess API initialization */
		PROCESS_INFORMATION pi = { 0 };
		STARTUPINFO startupInfo = { sizeof(STARTUPINFO) };

		if (!CreateProcessW(ExePath.c_str(), lpCommandLine, 0, 0, FALSE, DETACHED_PROCESS | CREATE_UNICODE_ENVIRONMENT, 0, FilePath.c_str(), &startupInfo, &pi))
		{
			//stream << GetLastError();
			return false;     // Cannot call CloseHandle if failed.
		}

		// Close process and thread handles. 
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
		return true;
	}
	catch (std::exception ex)
	{
		std::string message = "Exception while running hpReport : " + std::string(ex.what());
		//stream << message;
		return false;
	}
}
