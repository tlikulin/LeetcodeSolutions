#include <vector>
#include <array>
#include <string>


class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.empty()) return {};

        std::array<std::string, 8> mapping = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        size_t n = digits.size();
        std::vector<std::string> ans;
        std::string sol;

        letterCombinations_backtrack(digits, ans, sol, mapping, 0, n);
        return ans;
    }

    void letterCombinations_backtrack(const std::string& digits, std::vector<std::string>& ans, std::string& sol, const auto& mapping, size_t level, size_t n) {
        if (level == n) {
            ans.push_back(sol);
            return;                
        }

        for (char c : mapping[digits[level]-'2']) {
            sol.push_back(c);
            letterCombinations_backtrack(digits, ans, sol, mapping, level+1, n);
            sol.pop_back();
        }
    }
};