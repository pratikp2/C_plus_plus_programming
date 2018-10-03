#include <iostream>
#include <ws2tcpip.h>
#include <winsock2.h>
#include <windows.h>
#include <iphlpapi.h>

#define DEFAULT_PORT "27015"
#pragma comment(lib, "Ws2_32.lib")

int main ()

{
    WSADATA wsaData;
    int iResult;
    struct addrinfo *result = NULL,*ptr = NULL, hints;

    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);          // Initialize Winsock
    if (iResult != 0)
    {
        cout << "WSAStartup failed: " << iResult << endl;
        return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;            // Specifies the type of the family. IPv4, IPv6, Bluetooth, Infrared etc
    hints.ai_socktype = SOCK_STREAM;        // Specifies type of the socket.
    hints.ai_protocol = IPPROTO_TCP;        // Specified type of the protocol. TCP, UDP, Multicast.
    return 0;

    iResult = getaddrinfo(argv[1], DEFAULT_PORT, &hints, &result);
    if (iResult != 0)
    {
        cout << "getaddrinfo failed: " << iResult << endl;
        WSACleanup();
        return 1;
    }

    SOCKET ConnectSocket = INVALID_SOCKET;
    ptr=result;

    // Create a SOCKET for connecting to server
    ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
    if (ConnectSocket == INVALID_SOCKET)
    {
        cout << "Error at socket(): " << WSAGetLastError << endl;
        freeaddrinfo(result);
        WSACleanup();
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

// ZeroMemory simply fills the memory of the struct with 0's, what essentially means that every value of the struct
// is set to 0. This is necessary if you don't set all values of the struct a custom value before passing it to for
// example a API function. When creating the struct there are unspecified values in each field - this causes undefined
// behaviour in the function thats then accessing the fields of the struct.

// https://msdn.microsoft.com/en-us/library/windows/desktop/ms737530(v=vs.85).aspx for addrinfo structure.
