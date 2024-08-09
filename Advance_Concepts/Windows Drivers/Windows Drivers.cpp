#include <windows.h>
#include <psapi.h>
#include <tchar.h>
#include <stdio.h>
#include <iostream>
#include <setupapi.h>

// To ensure correct resolution of symbols, add Psapi.lib to TARGETLIBS
// and compile with -DPSAPI_VERSION=1

#define ARRAY_SIZE 1024

void EnumerateDeviceDrivers()
{
    LPVOID drivers[ARRAY_SIZE];
    DWORD cbNeeded;
    int cDrivers, i;

    if (EnumDeviceDrivers(drivers, sizeof(drivers), &cbNeeded) && cbNeeded < sizeof(drivers))
    {
        TCHAR szDriver[ARRAY_SIZE];
        TCHAR fzDriver[ARRAY_SIZE];
        cDrivers = cbNeeded / sizeof(drivers[0]);

        _tprintf(TEXT("There are %d drivers:\n"), cDrivers);
        for (i = 0; i < cDrivers; i++)
        {
            if (GetDeviceDriverBaseName(drivers[i], szDriver, sizeof(szDriver) / sizeof(szDriver[0])))
                _tprintf(TEXT("%d: %s\n"), i + 1, szDriver);

            if (GetDeviceDriverFileName(drivers[i], fzDriver, sizeof(szDriver) / sizeof(szDriver[0])))
                _tprintf(TEXT("%s\n\n"), fzDriver);
        }
    }
    else
        _tprintf(TEXT("EnumDeviceDrivers failed; array size needed is %d\n"), cbNeeded / sizeof(LPVOID));
}

void print_property(__in HDEVINFO hDevInfo, __in SP_DEVINFO_DATA DeviceInfoData, __in PCWSTR Label, __in DWORD Property)
{
    DWORD  DataT;
    LPTSTR buffer = NULL;
    DWORD  buffersize = 0;

    while (!SetupDiGetDeviceRegistryProperty(hDevInfo, &DeviceInfoData, Property, &DataT, (PBYTE)buffer, buffersize, &buffersize))
    {
        if (ERROR_INSUFFICIENT_BUFFER == GetLastError())
        {
            if (buffer)
                LocalFree(buffer);

            buffer = (LPTSTR)LocalAlloc(LPTR, buffersize * 2);
        }
        else
            break;  
    }

    wprintf(L"%s %s\n", Label, buffer);

    if (buffer)
        LocalFree(buffer);
}

int setupdi_version()
{
    HDEVINFO hDevInfo;
    SP_DEVINFO_DATA DeviceInfoData;
    DWORD i;

    // Create a HDEVINFO with all present devices.
    hDevInfo = SetupDiGetClassDevs(NULL, 0, 0, DIGCF_PRESENT | DIGCF_ALLCLASSES);

    if (INVALID_HANDLE_VALUE == hDevInfo)
    {
        // Insert error handling here.
        return 1;
    }

    // Enumerate through all devices in Set.

    DeviceInfoData.cbSize = sizeof(SP_DEVINFO_DATA);

    for (i = 0; SetupDiEnumDeviceInfo(hDevInfo, i, &DeviceInfoData); i++)
    {
        LPTSTR buffer = NULL;
        DWORD  buffersize = 0;

        print_property(hDevInfo, DeviceInfoData, L"Friendly name :", SPDRP_FRIENDLYNAME);

        while (!SetupDiGetDeviceInstanceId(hDevInfo, &DeviceInfoData, buffer, buffersize, &buffersize))
        {
            if (buffer)
                LocalFree(buffer);


            if (ERROR_INSUFFICIENT_BUFFER == GetLastError())
                buffer = (LPTSTR)LocalAlloc(LPTR, buffersize * 2);
            else
            {
                wprintf(L"error: could not get device instance id (0x%x)\n", GetLastError());
                break;
            }
        }

        if (buffer)
            wprintf(L"\tDeviceInstanceId : %s\n", buffer);

        print_property(hDevInfo, DeviceInfoData, L"\tClass :", SPDRP_CLASS);
        print_property(hDevInfo, DeviceInfoData, L"\tClass GUID :", SPDRP_CLASSGUID);
    }

    if (NO_ERROR != GetLastError() && ERROR_NO_MORE_ITEMS != GetLastError())
    {
        // Insert error handling here.
        return 1;
    }

    SetupDiDestroyDeviceInfoList(hDevInfo);
    return 0;
}

int main()
{
    //EnumerateDeviceDrivers();
    setupdi_version();
    std::cout << "Program End" << std::endl;
    std::system("pause");
    return 0;
}