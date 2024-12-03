class Solution {
public:
    bool isAnagram(string s, string t) {
        array<int, 26> counter = { 0 };
        for (auto c : s)
            ++counter[c - 'a'];
        for (auto c : t)
            --counter[c - 'a'];
        return all_of(counter.begin(), counter.end(), [](int val) { return val == 0; });
    }
};