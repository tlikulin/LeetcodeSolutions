#include <vector>
#include <algorithm>

class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        int n = static_cast<int>(nums.size());

        int subsum = 0;
        for (int i = 0; i < k; ++i)
            subsum += nums[i];
        double maxAvg = static_cast<double>(subsum) / k;

        for (int i = k; i < n; ++i) {
            subsum -= nums[i - k];
            subsum += nums[i];
            maxAvg = std::max(maxAvg, static_cast<double>(subsum) / k);
        }

        return maxAvg;
    }
};