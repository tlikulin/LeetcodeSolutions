class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result;
        for (int& i : nums) {
            i *= i;
            result.push_back(0);
        }
        int* l_ptr = &nums.front();
        int* r_ptr = &nums.back();
        int index = result.size() - 1;
        while (l_ptr != r_ptr){
            if (*l_ptr > *r_ptr) {
                result[index] = *l_ptr;
                l_ptr++;
            } 
            else {
                result[index] = *r_ptr;
                r_ptr--;
            }
            index--;
        }
        result[0] = *l_ptr;
        return result; 
    }
};