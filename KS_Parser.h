#ifndef KS_PARSER_H
#define KS_PARSER_H

#include <vector>
#include <utility>
#include <string>

class KS_Parser {
public:
    int n;
    int W;
    std::vector<std::pair<int, int>> items;

    bool readInput(const std::string &filename);
};

#endif
