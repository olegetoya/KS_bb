#ifndef KS_SOLVER_H
#define KS_SOLVER_H

#include <vector>
#include <utility>

struct Node {
    int level, profit, weight;
    float bound;
    std::vector<int> path;
};

class Compare {
public:
    bool operator()(Node &n1, Node &n2) {
        return n1.bound < n2.bound;
    }
};

class KS_Solver {
public:
    int knapsack(const std::vector<std::pair<int, int>> &items, int n, int W);
    void printResult();

private:
    int maxProfit = 0;
    int remainingWeight = 0;
    std::vector<int> solution;
};

#endif
