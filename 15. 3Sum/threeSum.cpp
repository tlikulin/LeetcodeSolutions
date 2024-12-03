class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int size = static_cast<int>(nums.size());
        for (int i = 0; i < size - 2; ++i) {
            if (nums[i] > 0)
                return res;
            int L = i + 1;
            int R = size - 1;
            while (L < R) {
                int sum = nums[i] + nums[L] + nums[R];
                if (sum == 0) {
                    res.push_back({nums[i], nums[L], nums[R]});
                    do ++L; while (L < R && nums[L] == res.back()[1]);
                    do --R; while (L < R && nums[R] == res.back()[2]);
                }
                else if (sum < 0)
                    ++L;
                else
                    --R;
            }
            while (i < size - 2 && nums[i+1] == nums[i])
                 ++i;
        }
        return res;
    }
};