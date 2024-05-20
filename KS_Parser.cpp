#include "KS_Parser.h"
#include <fstream>
#include <iostream>

bool KS_Parser::readInput(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return false;
    }

    file >> n >> W;
    items.resize(n);
    for (int i = 0; i < n; i++) {
        file >> items[i].first >> items[i].second;
    }

    file.close();
    return true;
}
