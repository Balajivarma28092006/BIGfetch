#ifndef CONFIGREADER_H
#define CONFIGREADER_H

#include <string>
#include <nlohmann/json.hpp>
#include "colors.h"

class ConfigReader {
    public:
        static void load(const std::string& path);
        static bool showOS();
        static bool showHelper();
        static bool showRAM();
        static bool showCPU();
        static bool showUSERNAME();
        static bool showHOSTNAME();
        static bool showDISKSPACE();
        static bool showUPTIME();
        static bool showCOLORS();
        static bool showBATTERY();
        static bool showASCII();

        static Colors::Code getColor(const std::string &key, Colors::Code fallback = Colors::DEFAULT);
    
    private:
        static nlohmann::json config;
};

#endif