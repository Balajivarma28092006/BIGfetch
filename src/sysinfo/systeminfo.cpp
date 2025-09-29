#include "systeminfo.h"


std::string SystemInfo::getOS() {
    OSVERSIONINFOEXW osvi;
    ZeroMemory(&osvi, sizeof(OSVERSIONINFOEXW));
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEXW);
    // RtlGetVersion((RTL_OSVERSIONINFOEXW*)&osvi);

    //using GetVersionExW
    #pragma warning(disable : 4996)
    if (!GetVersionExW((OSVERSIONINFOW*)&osvi)){
        return "Error: GetVersionEx failed with error " + std::to_string(GetLastError());
    }

    #pragma warning(default : 4996);
    std::string osName = "Windows";
    if (osvi.dwMajorVersion == 10 && osvi.dwMinorVersion == 0) {
            osName += osvi.wProductType == VER_NT_WORKSTATION ? (osvi.dwBuildNumber >= 22000 ? "11" : "10") : "Server";
        } else if (osvi.dwMajorVersion == 6) {
            switch (osvi.dwMinorVersion) {
                case 1: osName += osvi.wProductType == VER_NT_WORKSTATION ? "7" : "Server 2008 R2"; break;
                case 2: osName += osvi.wProductType == VER_NT_WORKSTATION ? "8" : "Server 2012"; break;
                case 3: osName += osvi.wProductType == VER_NT_WORKSTATION ? "8.1" : "Server 2012 R2"; break;
            }
        } else {
            osName += "Unknown";
        }

        osName += " (Version " + std::to_string(osvi.dwMajorVersion) + "." +
                  std::to_string(osvi.dwMinorVersion) + "." +
                  std::to_string(osvi.dwBuildNumber) + ")";
        return osName;
}

std::string SystemInfo::getCPU(){
    HKEY hKey;
    char cpuName[256];
    DWORD bufSize = sizeof(cpuName);

    if (RegOpenKeyExA(HKEY_LOCAL_MACHINE,
                      "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",
                      0, KEY_READ, &hKey) == ERROR_SUCCESS) {
        RegQueryValueExA(hKey, "ProcessorNameString", nullptr, nullptr,
                         (LPBYTE)cpuName, &bufSize);
        RegCloseKey(hKey);
        return std::string(cpuName);
    }
    return "Unknown CPU";
}

std::string SystemInfo::getRAM(){
    MEMORYSTATUSEX meminfo;
    meminfo.dwLength = sizeof(MEMORYSTATUSEX);
    if(!GlobalMemoryStatusEx(&meminfo)){
        return "Error: GloablMemoruStatusEx failed to load";
    }

    DWORDLONG totalMemMB = meminfo.ullTotalPhys / (1024 * 1024);
    DWORDLONG usedMemMB = (meminfo.ullTotalPhys - meminfo.ullAvailPhys) / (1024 * 1024);
    return std::to_string(usedMemMB) + " MB / " + std::to_string(totalMemMB) + " MB";
}

std::string SystemInfo::getHOSTNAME(){
    char buffer[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = sizeof(buffer);
    if(GetComputerName(buffer, &size)){
        return std::string(buffer);
    }
    return "Unknown Hostname";
}

std::string SystemInfo::getUSERNAME(){
    char buffer[256];
    DWORD size = sizeof(buffer);
    if(GetUserNameA(buffer, &size)){
        return std::string(buffer);
    }
    return "Unknown User";
}

std::string SystemInfo::getDISKSPACE(){
    ULARGE_INTEGER freeBytesAvailable, totalBytes, freeBytes;
    if(GetDiskFreeSpaceExA("C:\\", &freeBytesAvailable, &totalBytes, &freeBytes)){
        DWORDLONG totalGB = totalBytes.QuadPart / (1024*1024*1024);
        DWORDLONG freeGB = freeBytes.QuadPart / (1024*1024*1024);
        return std::to_string(totalGB - freeGB) + " GB (Used) / " + std::to_string(totalGB) + " GB";
    }
    return "Error: Disk info Unavailable";
}

std::string SystemInfo::getUPTIME() {
    ULONGLONG uptimeMS = GetTickCount64();

    ULONGLONG seconds = uptimeMS / 1000;
    ULONGLONG minutes = seconds / 60;
    ULONGLONG hours   = minutes / 60;
    ULONGLONG days    = hours / 24;

    seconds %= 60;
    minutes %= 60;
    hours %= 24;

    std::string uptime = std::to_string(days) + "d " +
                         std::to_string(hours) + "h " +
                         std::to_string(minutes) + "m " +
                         std::to_string(seconds) + "s";
    return uptime;
}

std::string SystemInfo::getBATTERY() {
    SYSTEM_POWER_STATUS status;
    if (!GetSystemPowerStatus(&status)) {
        return "Battery info unavailable";
    }

    std::string powerLine = (status.ACLineStatus == 1) ? "Plugged In" : "On Battery";
    std::string battery = (status.BatteryLifePercent != 255) ? 
                          std::to_string(status.BatteryLifePercent) + "%" : "Unknown";

    return powerLine + " (" + battery + ")";
}