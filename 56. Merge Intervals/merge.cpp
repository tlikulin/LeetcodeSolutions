#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        int size = intervals.size();
        sort(intervals.begin(), intervals.end());
        std::vector<std::vector<int>> res = {intervals[0]};
        for (int i = 1; i < size ; i++) {
            if (res.back()[1] < intervals[i][0])
                res.emplace_back(intervals[i]);
            else {
                res.back()[0] = std::min(res.back()[0], intervals[i][0]);
                res.back()[1] = std::max(res.back()[1], intervals[i][1]);
            }
        }
        return res;
    }
};