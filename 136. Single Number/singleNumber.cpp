#include <numeric>
#include <vector>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        return std::reduce(nums.begin(), nums.end(), 0, [](int i, int j) { return i ^ j; });
    }
};