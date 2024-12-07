#include <string>

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        if (s.empty()) return true;
        int s_ptr = 0;
        int t_ptr = 0;
        while (s_ptr != s.size() && t_ptr != t.size()) {
            if (s[s_ptr] == t[t_ptr]) s_ptr++;
            t_ptr++;
        }
        return s_ptr == s.size();
    }
};