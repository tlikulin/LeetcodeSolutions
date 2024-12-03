class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashtable(nums.begin(), nums.end());
        int max = 0;
        int count = 1;
        for (int const& i : hashtable) {
            if (!hashtable.contains(i - 1)) {
                while (hashtable.contains(i+count)) 
                    ++count;
                max = count > max ? count : max;
                count = 1;
            }
        }
        return max;
    }
};