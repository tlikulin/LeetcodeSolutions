class Solution {
public:
    string sortString(string const& s) const{
        array<int, 26> counter = {0};
        for (auto c : s)
            ++counter[c-'a'];
        string res;
        for (char i = 0; i < 26; ++i)
            for (int j = 0; j < counter[i]; ++j)
                res.push_back('a' + i);
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> hashmap;
        int size = strs.size();
        for (int i = 0; i < size; ++i) {
            hashmap[sortString(strs[i])].push_back(strs[i]);
        }
        for (const auto& [k, v] : hashmap) {
            res.push_back(hashmap[k]);
        }
        return res;
    }
};