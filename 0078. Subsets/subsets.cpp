#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        auto n = static_cast<int>(nums.size());

        int max = 1 << n;
        for (int i = 0; i < max; ++i) {
            std::vector<int> sub;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    sub.push_back(nums[j]);
                }
            }
            ans.push_back(sub);
        }

        return ans;
    }
};