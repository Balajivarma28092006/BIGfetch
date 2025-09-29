#pragma once
#include <windows.h>
#include <string>
#include <unordered_map>

namespace Colors {
    enum Code {
        DEFAULT = 7,
        RED     = 12,
        GREEN   = 10,
        BLUE    = 9,
        YELLOW  = 14,
        CYAN    = 11,
        MAGENTA = 13,
        WHITE   = 15
    };

    void setColor(Code color);
    void resetColor();
    void printColored(const std::string& text, Code color);

    Code fromString(const std::string& name);
}
