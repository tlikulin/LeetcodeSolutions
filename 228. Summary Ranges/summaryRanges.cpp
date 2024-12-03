class Solution {
public:
    string getRange(int lower, int upper) {
        if (lower > upper)
            return {};
        else if (lower == upper)
            return to_string(lower);
        string str;
        str.assign(to_string(lower));
        str.append("->");
        str.append(to_string(upper));
        return str;
    }
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty())
            return {};
        int lower = nums[0];
        int upper = lower;
        vector<string> ans;
        auto size = (int)nums.size();
        for (int i = 1; i < size; i++) {
            if (upper + 1 == nums[i])
                upper++;
            else {
                ans.emplace_back(getRange(lower, upper));
                upper = lower = nums[i];
            }
        }
        ans.emplace_back(getRange(lower, upper));
        return ans;
    }
};