class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        for (int i : nums) {
            if (!count) {
                candidate = i;
                ++count;
            } else if (candidate == i)
                ++count;
            else
                --count;
        }
        return candidate;
    }
};