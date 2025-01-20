#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        auto size = (int) nums.size();
        std::vector<int> ans(size, 1);
        int temp = 1;
        for (int i = 0; i < size; i++){
            ans[i] *= temp;
            temp *= nums[i];
        }
        temp = 1;
        for (int i = size - 1; i >= 0; i--){
            ans[i] *= temp;
            temp *= nums[i];
        }
        return ans;
    }
};