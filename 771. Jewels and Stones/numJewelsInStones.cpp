#include <string>
#include <unordered_set>

class Solution {
public:
    int numJewelsInStones(std::string jewels, std::string stones) {
        std::unordered_set<char> is_jewel;
        for (auto s : jewels)
            is_jewel.insert(s);
        int count = 0;
        for (auto s : stones)
            if (is_jewel.find(s) != is_jewel.end())
                count++;
        return count;
    }
};