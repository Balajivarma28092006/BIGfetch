#include "display.h"
#include "colors.h"
#include <iostream>
#include <vector>

void Display::printColorBars() {
    using namespace Colors;

    // Choose the colors you want for the blocks
    std::vector<Code> codes = { RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE };

    // Print each block
    for (auto c : codes) {
        setColor(c);              // Set text color
        std::cout << "   ";       // Three spaces as a block
    }

    resetColor();                 // Reset color after row
    std::cout << "\n";
}
