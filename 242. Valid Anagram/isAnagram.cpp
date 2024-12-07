#include <array>
#include <string>
#include <algorithm>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::array<int, 26> counter = { 0 };
        for (auto c : s)
            ++counter[c - 'a'];
        for (auto c : t)
            --counter[c - 'a'];
        return std::all_of(counter.begin(), counter.end(), [](int val) { return val == 0; });
    }
};