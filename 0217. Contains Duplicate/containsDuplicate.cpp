#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> set;
        for (int const& i : nums)
            if (set.find(i) == set.end())
                set.insert(i);
            else
                return true;
        return false;
    }
};