#include <string>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string pref = "";
        int size = strs[0].size();
        for (int i = 0; i < size; i++) {
            char c = strs[0][i];
            for (std::string& str : strs) {
                if (str[i] != c) return pref;
            }
            pref.push_back(c);
        }
        return pref;
    }
};