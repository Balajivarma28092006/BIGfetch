#ifndef SYSTEMINFO_H
#define SYSTEMINFO_H

#include <string>
#include <windows.h>
#include <sstream>
#include <winternl.h>
#include <wbemidl.h> //for wmi cpu info

class SystemInfo {
public:
    SystemInfo() {
        CoInitializeEx(0, COINIT_MULTITHREADED);
    }

    ~SystemInfo() {
        CoUninitialize();
    }

    static std::string getOS();
    static std::string getCPU();
    static std::string getRAM();
    static std::string getGPU();
    static std::string getBATTERY();
    static std::string getHOSTNAME();
    static std::string getUSERNAME();
    static std::string getDISKSPACE();
    static std::string getUPTIME();
};

#endif
