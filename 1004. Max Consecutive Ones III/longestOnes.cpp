class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        auto n = static_cast<int>(nums.size());
        int L = 0; int R = 0;
        int maxCount = 0;

        for (; R < n; ++R) {
            if (nums[R] == 0) {
                if (k > 0) {
                    --k;
                } else {
                    maxCount = max(maxCount, R - L);
                    while (nums[L] == 1) ++L;
                    ++L;
                }
            }
        }

        maxCount = max(maxCount, R - L);
        return maxCount;
    }
};