#include <vector>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int n = (int)nums.size();        
        int goal = n - 1;

        for (int pos = n - 2; pos >= 0; pos--) {
            if (pos + nums[pos] >= goal)
                goal = pos;
        }

        return goal == 0;
    }
};