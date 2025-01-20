#include <vector>

class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        int n = (int)cost.size();
        int prev = cost[0], curr = cost[1];

        for (int i = 2; i < n; i++) {
            int temp = curr;
            curr = cost[i] + std::min(prev, curr);
            prev = temp;
        }

        return std::min(prev, curr);
    }
};