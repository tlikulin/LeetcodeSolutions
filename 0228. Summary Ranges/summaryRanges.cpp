#include <string>
#include <vector>

class Solution {
public:
    std::string getRange(int lower, int upper) {
        if (lower > upper)
            return {};
        else if (lower == upper)
            return std::to_string(lower);
        std::string str;
        str.assign(std::to_string(lower));
        str.append("->");
        str.append(std::to_string(upper));
        return str;
    }
    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        if (nums.empty())
            return {};
        int lower = nums[0];
        int upper = lower;
        std::vector<std::string> ans;
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