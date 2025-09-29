#include "ascii.h"
#include <fstream>
#include <iostream>
#include "colors.h"
#include <windows.h>

void ASCII::printFromFile(const std::string& path) {
    // 1️⃣ Set console to UTF-8
    SetConsoleOutputCP(CP_UTF8);

    // 2️⃣ Open file as UTF-8
    std::ifstream file(path, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Failed to open ASCII file: " << path << "\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        // Print line with color (ANSI)
        Colors::printColored(line + "\n", Colors::CYAN);
    }

    file.close();
}
