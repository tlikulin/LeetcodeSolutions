#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int n = (int)nums.size();
        int currMax = nums[0];
        int currSubarray = nums[0];

        for (int i = 1; i < n; i++) {
            currSubarray = std::max(nums[i], nums[i] + currSubarray);
            currMax = std::max(currMax, currSubarray);
        }

        return currMax;
    }
};