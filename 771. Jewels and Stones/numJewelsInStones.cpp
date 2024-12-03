class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> is_jewel;
        for (auto s : jewels)
            is_jewel.insert(s);
        int count = 0;
        for (auto s : stones)
            if (is_jewel.find(s) != is_jewel.end())
                count++;
        return count;
    }
};