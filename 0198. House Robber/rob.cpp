#include <vector>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return std::max(nums[0], nums[1]);

        int prevprev = nums[0], prev = nums[1], curr = nums[2] + nums[0];

        for (int i = 3; i < n; i++) {
            int next = nums[i] + std::max(prev, prevprev);
            prevprev = prev;
            prev = curr;
            curr = next;
        }

        return std::max(curr, prev);
    }
};