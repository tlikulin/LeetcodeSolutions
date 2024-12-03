class Solution {
public:
    int findMin(vector<int>& nums) {
        int L = 0;
        int R = static_cast<int>(nums.size()) - 1;
        while (L < R) {
            int M = L + (R - L) / 2;
            if (nums[M] > nums[R])
                L = M + 1;
            else
                R = M;
        }
        return nums[L];
    }
};