#include <string>
#include <limits.h>
#include <array>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        auto n = static_cast<int>(s.size());
        int L = 0; int R;
        int maxLength = 0;
        std::array<bool, CHAR_MAX+1> alreadyHas = {false};
        for (R = 0; R < n; ++R) {
            char c = s[R];
            if (alreadyHas[c]) {
                maxLength = std::max(maxLength, R - L);
                while (s[L] != c) {
                    alreadyHas[s[L]] = false;
                    ++L;
                }
                ++L;
            } else
                alreadyHas[c] = true;
        }
        maxLength = std::max(maxLength, R - L);
        return maxLength;
    }
};