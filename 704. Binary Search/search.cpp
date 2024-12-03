class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto size = static_cast<int>(nums.size());
        int left = 0;
        int right = size - 1;
        int mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return nums[left] == target ? left : -1;
    }
};