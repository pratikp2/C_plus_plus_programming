#include <iostream>
#include <ws2tcpip.h>
#include <winsock2.h>
#include <windows.h>
#include <iphlpapi.h>
#pragma comment(lib, "Ws2_32.lib")

int main ()

{
    WSADATA wsaData;
    int iResult;

    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);          // Initialize Winsock
    if (iResult != 0)
    {
        cout << "WSAStartup failed: " << iResult << endl;
        return 1;
    }
    return 0;

}

//The Winsock2.h header file internally includes core elements from the Windows.h header file, so there
//is not usually an #include line for the Windows.h header file in Winsock applications.

// The WSAStartup function is called to initiate use of WS2_32.dll.

// The WSADATA structure contains information about the Windows Sockets implementation. The MAKEWORD
// (2,2) parameter of WSAStartup makes a request for version 2.2 of Winsock on the system, and sets
// the passed version as the highest version of Windows Sockets support that the caller can use.
