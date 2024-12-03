class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int current_max = 0;
        int current_score = 0;
        for (int i : nums) {
            if (i) current_score++;
            else {
                current_max = current_score > current_max ? current_score : current_max;
                current_score = 0;
            }
        }
        return current_score > current_max ? current_score : current_max;
    }
};