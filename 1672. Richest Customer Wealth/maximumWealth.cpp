#include <vector>

class Solution {
public:
    int maximumWealth(std::vector<std::vector<int>>& accounts) {
        int current_max = 0;

        for (const auto& customer : accounts) {
            int wealth = 0;
            for (int bank : customer) {
                wealth += bank;
            }
            if (wealth > current_max) 
                current_max = wealth;
        }

        return current_max;
    }
};