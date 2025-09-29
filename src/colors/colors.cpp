#include "colors.h"
#include <iostream>
#include <algorithm>

namespace Colors {
    static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    void setColor(Code color) {
        SetConsoleTextAttribute(hConsole, color);
    }

    void resetColor() {
        SetConsoleTextAttribute(hConsole, DEFAULT);
    }

    void printColored(const std::string& text, Code color) {
        setColor(color);
        std::cout << text;
        resetColor();
    }

    Code fromString(const std::string& name){
        static std::unordered_map<std::string, Code>mapping = {
            {"DEFAULT", DEFAULT},
            {"RED", RED},
            {"GREEN", GREEN},
            {"BLUE", BLUE},
            {"YELLOW", YELLOW},
            {"CYAN", CYAN},
            {"MAGENTA", MAGENTA},
            {"WHITE", WHITE}
        };

        std::string upper = name;
        std::transform(upper.begin(), upper.end(), upper.begin(), ::toupper);

        auto it = mapping.find(upper);
        if (it != mapping.end()){
            return it->second;
        }
        return DEFAULT;
    }
}
