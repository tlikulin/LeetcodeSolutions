#include <vector>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        int n = (int)nums.size();
        std::vector<int> dp(n, 1);

        int maxFound = 1;
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] > nums[i])
                    dp[i] = std::max(1 + dp[j], dp[i]);
            }
            maxFound = std::max(maxFound, dp[i]);
        }

        return maxFound;
    }
};