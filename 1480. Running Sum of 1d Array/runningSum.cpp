#include <vector>

class Solution {
public:
    std::vector<int> runningSum(std::vector<int>& nums) {
        std::vector<int> result;
        result.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            result.push_back(result[i-1] + nums[i]);
        }
        return result;
    }
};