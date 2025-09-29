#include "configreader.h"
#include <fstream>
#include <iostream>

nlohmann::json ConfigReader::config;

void ConfigReader::load(const std::string& path){
    std::ifstream file(path);
    if(!file.is_open()){
        std::cerr << "Failed to open config file: " << path << "\n";
        return;
    }
    file >> config;
}

bool ConfigReader::showOS() {
    return config.contains("show") && config["show"].value("os", true);
}

bool ConfigReader::showHelper() {
    return config.contains("show") && config["show"].value("helper", true);
}

bool ConfigReader::showRAM() {
    return config.contains("show") && config["show"].value("ram", true);
}

Colors::Code ConfigReader::getColor(const std::string& key, Colors::Code fallback) {
    if (config.contains("colors") && config["colors"].contains(key)) {
        std::string value = config["colors"][key].get<std::string>();
        return Colors::fromString(value);
    }
    return fallback;
}

bool ConfigReader::showCPU() {
    return config.contains("show") && config["show"].value("cpu", true);
}

bool ConfigReader::showUSERNAME() {
    return config.contains("show") && config["show"].value("username", true);
}

bool ConfigReader::showHOSTNAME() {
    return config.contains("show") && config["show"].value("hostname", true);
}

bool ConfigReader::showDISKSPACE() {
    return config.contains("show") && config["show"].value("diskspace", true);
}

bool ConfigReader::showUPTIME() {
    return config.contains("show") && config["show"].value("uptime", true);
}

bool ConfigReader::showCOLORS() {
    return config.contains("show") && config["show"].value("colorbar", true);
}

bool ConfigReader::showBATTERY() {
    return config.contains("show") && config["show"].value("battery", true);
}

bool ConfigReader::showASCII() {
    return config.contains("show") && config["show"].value("ascii", true);
}