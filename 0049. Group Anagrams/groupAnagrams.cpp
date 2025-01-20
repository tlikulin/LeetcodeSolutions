#include <vector>
#include <unordered_map>
#include <string>
#include <array>

class Solution {
public:
    std::string sortString(std::string const& s) const{
        std::array<int, 26> counter = {0};
        for (auto c : s)
            ++counter[c-'a'];
        std::string res;
        for (char i = 0; i < 26; ++i)
            for (int j = 0; j < counter[i]; ++j)
                res.push_back('a' + i);
        return res;
    }
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::vector<std::vector<std::string>> res;
        std::unordered_map<std::string, std::vector<std::string>> hashmap;
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