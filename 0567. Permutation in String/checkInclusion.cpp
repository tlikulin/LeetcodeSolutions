#include <string>
#include <array>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        auto n = s2.size();
        auto k = s1.size();
        if (k > n) return false;

        std::array<int, 26> sourceCounter = {0};
        for (char c : s1)
            ++sourceCounter[c-'a'];
        std::array<int, 26> targetCounter = {0};
        
        int L = 0;
        for (int R = 0; R < n; ++R) {
            char c = s2[R];
            ++targetCounter[c-'a'];

            if (targetCounter == sourceCounter) return true;

            while (targetCounter[c-'a'] > sourceCounter[c-'a']) {
                --targetCounter[s2[L]-'a'];
                ++L;
            }
        }

        return false;
    }
};