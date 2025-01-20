#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> ans;
        std::string sol = "";

        generateParenthesis_backtrack(n, ans, sol, 0, 0);
        return ans;
    }

    void generateParenthesis_backtrack(int n, std::vector<std::string>& ans, std::string& sol, int count1, int count2) {
        if (count1 + count2 == 2*n) {
            ans.push_back(sol);
            return;
        }

        if (count1 < n) {
            sol.push_back('(');
            generateParenthesis_backtrack(n, ans, sol, count1+1, count2);
            sol.pop_back();
        }

        if (count1 > count2) {
            sol.push_back(')');
            generateParenthesis_backtrack(n, ans, sol, count1, count2+1);
            sol.pop_back();
        }
    }
};