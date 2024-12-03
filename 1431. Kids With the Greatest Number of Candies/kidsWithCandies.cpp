class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int threshold = *max_element(candies.begin(), candies.end()) - extraCandies;
        vector<bool> res;
        for (int& i : candies)
            res.push_back(i >= threshold);
        return res;
    }
};