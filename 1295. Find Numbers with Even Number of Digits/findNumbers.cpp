class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int i : nums) {
            int digits = 0;
            while (i) {
                i /= 10;
                digits++;
            }
            if (digits % 2 == 0) count++;
        }
        
        return count;
    }
};