#include <vector>
#include <algorithm>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        auto n = nums.size();
        int L = 0;
        int minLen = n + 1;
        int subsum = 0;
        
        for (int R = 0; R < n; ++R) {
            subsum += nums[R];
            while (subsum >= target) {
                minLen = std::min(minLen, R-L+1);
                subsum -= nums[L];
                ++L;
            }
        }

        return minLen == n+1 ? 0 : minLen;
    }
};