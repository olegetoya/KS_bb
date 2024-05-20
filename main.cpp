#include "KS_Parser.h"
#include "KS_Solver.h"

int main() {
    KS_Parser parser;
    if (!parser.readInput("input.txt")) {
        return 1;
    }

    KS_Solver solver;
    solver.knapsack(parser.items, parser.n, parser.W);
    solver.printResult();

    return 0;
}
