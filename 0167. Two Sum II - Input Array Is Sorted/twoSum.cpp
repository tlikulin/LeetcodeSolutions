#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int L = 0;
        int R = static_cast<int>(numbers.size()) - 1;
        while (L < R) {
            int sum = numbers[L] + numbers[R];
            if (sum == target)
                return {L+1, R+1};
            else if (sum > target)
                --R;
            else
                ++L;
        }
        return {-1, -1};
    }
};