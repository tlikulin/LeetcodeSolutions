#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        int n = (int)coins.size();
        std::sort(coins.begin(), coins.end());
        std::vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i - coin < 0)
                    break;

                if (dp[i - coin] != INT_MAX)
                    dp[i] = std::min(dp[i], 1 + dp[i - coin]);
            }
        }

        return dp.back() == INT_MAX ? -1 : dp.back();
    }
};