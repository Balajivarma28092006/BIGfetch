#include <iostream>
#include "systeminfo.h"
#include "helper.h"
#include "configreader.h"
#include "colors.h"
#include "display.h"
#include "ascii.h"


int main() {
    ConfigReader::load("config/config.json");

    auto titleColor = ConfigReader::getColor("title");
    auto labelColor = ConfigReader::getColor("label");
    auto valueColor = ConfigReader::getColor("value");

    ASCII::printFromFile("src/ascii/logo.txt");
    
    if(ConfigReader::showUSERNAME()){
        std::cout << "\n";
        Colors::printColored("User: ", labelColor);
        Colors::printColored(SystemInfo::getUSERNAME() + "\n", valueColor);
    }

    if(ConfigReader::showHOSTNAME()){
        Colors::printColored("Host: ", labelColor);
        Colors::printColored(SystemInfo::getHOSTNAME() + "\n", valueColor);
    }

    if (ConfigReader::showOS()) {
        Colors::printColored("System: ", labelColor);
        Colors::printColored(SystemInfo::getOS() + "\n", valueColor);
    }

    if (ConfigReader::showCPU()){
        Colors::printColored("CPU: ", labelColor);
        Colors::printColored(SystemInfo::getCPU() + "\n", valueColor);
    }

    if(ConfigReader::showBATTERY()) {
        Colors::printColored("Battery: ", labelColor);
        Colors::printColored(SystemInfo::getBATTERY() + "\n", valueColor);
    }
    
    if (ConfigReader::showRAM()) {
        Colors::printColored("Memory: ", labelColor);
        Colors::printColored(SystemInfo::getRAM() + "\n", valueColor);
    }

    if (ConfigReader::showDISKSPACE()){
        Colors::printColored("Disk: ", labelColor);
        Colors::printColored(SystemInfo::getDISKSPACE() + "\n", valueColor);
    }

    if (ConfigReader::showUPTIME()) {
        Colors::printColored("Uptime: ", labelColor);
        Colors::printColored(SystemInfo::getUPTIME() + "\n", valueColor);
    }


    if (ConfigReader::showHelper()) {
        Colors::printColored("Helper: ", labelColor);
        Colors::printColored(helperMessage() + "\n", valueColor);
    }

    if (ConfigReader::showCOLORS()) {
        std::cout << "\n";
        Display::printColorBars();
    }
    return 0;
}
