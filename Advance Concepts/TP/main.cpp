#include <windows.h>
#include <psapi.h>
#include <tchar.h>
#include <stdio.h>
#include <iostream>

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

int main()
{
    EnumerateDeviceDrivers();

    std::cout << "Program End" << std::endl;
    std::system("pause");
    return 0;
}