#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> ans;
        auto n = static_cast<int>(candidates.size());
        std::vector<int> sol;

        combinationSum_backtrack(candidates, n, ans, sol, -target, 0);
        return ans;
    }

    void combinationSum_backtrack(std::vector<int>& candidates, int n, std::vector<std::vector<int>>& ans, std::vector<int>& sol, int subsum, int startIndex) {
        if (subsum > 0) {
            return;
        }

        if (subsum == 0) {
            ans.push_back(sol);
            return;
        }
        
        for (int i = startIndex; i < n; ++i) {
            sol.push_back(candidates[i]);
            combinationSum_backtrack(candidates, n, ans, sol, subsum + candidates[i], i);
            sol.pop_back();
        }
    }
};