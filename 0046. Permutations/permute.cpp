#include <vector>
#include <cstddef>

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        auto n = nums.size();
        std::vector<std::vector<int>> ans;
        std::vector<int> sol = {};
        std::vector<bool> used(n, false);

        permute_backtrack(nums, ans, sol, used, n, 0);
        return ans;
    }

    void permute_backtrack(std::vector<int>& nums, std::vector<std::vector<int>>& ans, std::vector<int>& sol, std::vector<bool>& used, size_t& n, size_t level) {
        if (level == n) {
            ans.push_back(sol);
            return;
        }
        for (size_t i = 0; i < n; ++i) {
            if (used[i]) continue;

            sol.push_back(nums[i]);
            used[i] = true;
            permute_backtrack(nums, ans, sol, used, n, level+1);
            sol.pop_back();
            used[i] = false;
        }
    }
};