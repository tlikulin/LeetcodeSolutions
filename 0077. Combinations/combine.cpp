#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> ans;
        std::vector<int> sol;

        combine_backtrack(ans, sol, n, k, 0);
        return ans;
    }

    void combine_backtrack(std::vector<std::vector<int>>& ans, std::vector<int>& sol, int n, int k, int level) {
        if (level == k) {
            ans.push_back(sol);
            return;
        }
        
        for (int i = (level==0 ? 1 : sol.back()+1); (n-i+1) >= (k-level); ++i) {
                sol.push_back(i);
                combine_backtrack(ans, sol, n, k, level+1);
                sol.pop_back();
        }
    }
};