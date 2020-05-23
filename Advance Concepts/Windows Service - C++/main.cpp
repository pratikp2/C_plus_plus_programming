#include <windows.h>
#include <tchar.h>
#include <iostream>
#include <thread>
#include <dos.h>
//#include "WorkerClass.h"

#define SERVICE_NAME LPWSTR("Sample Practice Service")

SERVICE_STATUS g_ServiceStatus = { 0 };
SERVICE_STATUS_HANDLE g_StatusHandle = nullptr;
HANDLE g_ServiceStopEvent = INVALID_HANDLE_VALUE;


VOID WINAPI ServiceMain(DWORD, LPTSTR*);
VOID WINAPI ServiceCtrlHandler(DWORD);
DWORD WINAPI ServiceWorkerThread(LPVOID);
void ServiceWorkerSTDThread();

// Program Main Entry Point
int _tmain()
{
	SERVICE_TABLE_ENTRY ServiceTable[] = { {SERVICE_NAME,(LPSERVICE_MAIN_FUNCTION)ServiceMain},{NULL, NULL} };

	if (StartServiceCtrlDispatcher(ServiceTable) == FALSE)
		return GetLastError();

	// In the main entry point you quickly call StartServiceCtrlDispatcher so the SCM (Service Control Manager)
	// can call your Service Entry point(ServiceMain in the example above).You want to defer any initialization
	// until your Service Entry point, which is defined next.

	return 0;
}

// Service Entry Point
VOID WINAPI ServiceMain(DWORD argc, LPTSTR* argv)
{
	DWORD Status = E_FAIL;

	// Register Service Control Handler with the SCM
	g_StatusHandle = RegisterServiceCtrlHandler(SERVICE_NAME, ServiceCtrlHandler);

	if (g_StatusHandle == nullptr)
		return;

	// Inform Service Controller that service is starting
	ZeroMemory(&g_ServiceStatus, sizeof(g_ServiceStatus));
	g_ServiceStatus.dwServiceType = SERVICE_WIN32_OWN_PROCESS;
	g_ServiceStatus.dwControlsAccepted = 0;
	g_ServiceStatus.dwCurrentState = SERVICE_START_PENDING;
	g_ServiceStatus.dwWin32ExitCode = 0;
	g_ServiceStatus.dwServiceSpecificExitCode = 0;
	g_ServiceStatus.dwCheckPoint = 0;

	if (SetServiceStatus(g_StatusHandle, &g_ServiceStatus) == FALSE)
		OutputDebugString(_T("My Sample Service: ServiceMain: SetServiceStatus returned error"));

	// Performing Nesessary Tasks to start Service

	// 1. Create Service stop event to wait on later
	g_ServiceStopEvent = CreateEvent(nullptr, TRUE, FALSE, nullptr);

	if (g_ServiceStopEvent == nullptr)
	{
		// Error Creating Event
		// Telling service controller we have stopped and exiting
		g_ServiceStatus.dwControlsAccepted = 0;
		g_ServiceStatus.dwCurrentState = SERVICE_STOPPED;
		g_ServiceStatus.dwWin32ExitCode = GetLastError();
		g_ServiceStatus.dwCheckPoint = 1;

		if (SetServiceStatus(g_StatusHandle, &g_ServiceStatus) == FALSE)
			OutputDebugString(_T("My Sample Service: ServiceMain: SetServiceStatus returned error"));

		return;
	}

	// 2. Tell Service Controller that Servide has been started.
	g_ServiceStatus.dwControlsAccepted = SERVICE_ACCEPT_STOP;
	g_ServiceStatus.dwCurrentState = SERVICE_RUNNING;
	g_ServiceStatus.dwWin32ExitCode = 0;
	g_ServiceStatus.dwCheckPoint = 0;

	if (SetServiceStatus(g_StatusHandle, &g_ServiceStatus) == FALSE)
		OutputDebugString(_T("My Sample Service: ServiceMain: SetServiceStatus returned error"));

	// 3. Start the thread that will perform main task and wait for it to return.
	HANDLE hThread = CreateThread(nullptr, 0, ServiceWorkerThread, nullptr, 0, nullptr);
	WaitForSingleObject(hThread, INFINITE);

	//static std::unique_ptr<std::thread> SampleThread1;
	//SampleThread1.reset(new std::thread(ServiceWorkerSTDThread));
	//SampleThread1->detach();
	//SampleThread1->join();
	//Sleep(5000);

	// Perform Cleanup Task
	CloseHandle(&g_ServiceStopEvent);

	// Telling service controller that service has stopped.
	g_ServiceStatus.dwControlsAccepted = 0;
	g_ServiceStatus.dwCurrentState = SERVICE_STOPPED;
	g_ServiceStatus.dwWin32ExitCode = 0;
	g_ServiceStatus.dwCheckPoint = 3;

	if (SetServiceStatus(g_StatusHandle, &g_ServiceStatus) == FALSE)
		OutputDebugString(_T("My Sample Service: ServiceMain: SetServiceStatus returned error"));

	return;
}

VOID WINAPI ServiceCtrlHandler(DWORD CtrlCode)
{
	switch (CtrlCode)
	{
	case SERVICE_CONTROL_STOP:

		if (g_ServiceStatus.dwCurrentState != SERVICE_RUNNING)
			break;

		g_ServiceStatus.dwControlsAccepted = 0;
		g_ServiceStatus.dwCurrentState = SERVICE_STOP_PENDING;
		g_ServiceStatus.dwWin32ExitCode = 0;
		g_ServiceStatus.dwCheckPoint = 4;

		if (SetServiceStatus(g_StatusHandle, &g_ServiceStatus) == FALSE)
			OutputDebugString(_T("My Sample Service: ServiceCtrlHandler: SetServiceStatus returned error"));
		
		// This will signal the worker thread to start shutting down
		SetEvent(g_ServiceStopEvent);
		break;

	default:
		break;
	}

	// Requests such as SERVICE_CONTROL_CONTINUE, SERVICE_CONTROL_INTERROGATE, SERVICE_CONTROL_PAUSE,
	// SERVICE_CONTROL_SHUTDOWNand others supported by the Handler or HandlerEx function that can be
	// registered with the RegisterServiceCtrlHandler(Ex) function.
}

// Service Worker Thread
DWORD WINAPI ServiceWorkerThread(LPVOID lpparam)
{
	// periodically check if service has been requested to stop
	while (WaitForSingleObject(g_ServiceStopEvent, 0) != WAIT_OBJECT_0)
		Sleep(3000);
	
	return ERROR_SUCCESS;
}

void ServiceWorkerSTDThread()
{
	while (WaitForSingleObject(g_ServiceStopEvent, 0) != WAIT_OBJECT_0)
		Sleep(3000);
}

// Commands to start service
// sc create "My Sample Service" binPath= "C:\SampleService.exe"
// sc delete "My Sample Service" 

/* C++ Code to install and delete Service

SC_HANDLE h_manager = NULL;
SC_HANDLE h_service = NULL;

h_manager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);

h_service = CreateServiceW( 
    h_manager,                 // SCM database
    L"MyService",              // name of service
    L"My Service",             // display name
    SERVICE_ALL_ACCESS,        // desired access
    SERVICE_WIN32_OWN_PROCESS, // service type
    SERVICE_AUTO_START,        // start type
    SERVICE_ERROR_NORMAL,      // error control type
    L"c:\\abc.exe",            // path to service's binary
    NULL,                      // no load ordering group
    NULL,                      // no tag identifier
    NULL,                      // no dependencies
    L"NT AUTHORITY\\NetworkService",
    L"");                     // no password

CloseServiceHandle(h_service); 
CloseServiceHandle(h_manager); */