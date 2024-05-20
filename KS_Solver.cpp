#include "KS_Solver.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

float bound(Node u, int n, int W, const std::vector<std::pair<int, int>>& items) {
    if (u.weight >= W)
        return 0;

    int profit_bound = u.profit;
    int j = u.level + 1;
    int totweight = u.weight;

    while ((j < n) && (totweight + items[j].second <= W)) {
        totweight += items[j].second;
        profit_bound += items[j].first;
        j++;
    }

    if (j < n) {
        profit_bound += (W - totweight) * (items[j].first / double(items[j].second));
    }

    return profit_bound;
}

int KS_Solver::knapsack(const std::vector<std::pair<int, int>>& items, int n, int W) {
    std::priority_queue<Node, std::vector<Node>, Compare> Q;
    Node u, v;

    v.level = -1;
    v.profit = v.weight = 0;
    v.path.resize(n, 0);
    v.bound = bound(v, n, W, items);
    Q.push(v);

    while (!Q.empty()) {
        v = Q.top();
        Q.pop();

        if (v.bound <= maxProfit) continue;

        u.level = v.level + 1;
        if (u.level >= n) continue;

        u.weight = v.weight + items[u.level].second;
        u.profit = v.profit + items[u.level].first;
        u.path = v.path;
        u.path[u.level] = 1;

        if (u.weight <= W && u.profit > maxProfit) {
            maxProfit = u.profit;
            remainingWeight = W - u.weight;
            solution = u.path;
        }

        u.bound = bound(u, n, W, items);
        if (u.bound > maxProfit) {
            Q.push(u);
        }

        u.weight = v.weight;
        u.profit = v.profit;
        u.path[u.level] = 0;
        u.bound = bound(u, n, W, items);
        if (u.bound > maxProfit) {
            Q.push(u);
        }
    }

    return maxProfit;
}

void KS_Solver::printResult() {
    std::cout << "Maximum Profit: " << maxProfit << "\n";
    std::cout << "Remaining Weight: " << remainingWeight << "\n";
    std::ofstream outfile("output.txt");
    outfile << maxProfit << "\n" << remainingWeight << "\n";
    for (int s : solution) {
        std::cout << s << " ";
        outfile << s << " ";
    }
    std::cout << "\n";
    outfile.close();
}
