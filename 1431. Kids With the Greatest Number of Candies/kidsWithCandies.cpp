#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies) {
        int threshold = *std::max_element(candies.begin(), candies.end()) - extraCandies;
        std::vector<bool> res;
        for (int& i : candies)
            res.push_back(i >= threshold);
        return res;
    }
};