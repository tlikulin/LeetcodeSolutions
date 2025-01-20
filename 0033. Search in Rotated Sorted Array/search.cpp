#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        auto n = static_cast<int>(nums.size());
        int L = 0;
        int R = n - 1;
        while (L < R) {
            int M = L + (R - L) / 2;
            if (nums[M] > nums[R])
                L = M + 1;
            else
                R = M;
        }
        int k = L;
        L = 0;
        R = n - 1;
        while (L <= R) {
            int M = L + (R - L) / 2;
            if (nums[(M+k)%n] == target)
                return (M+k)%n;
            if (nums[(M+k)%n] < target)
                L = M + 1;
            else
                R = M - 1;
        }
        return -1;
    }
};