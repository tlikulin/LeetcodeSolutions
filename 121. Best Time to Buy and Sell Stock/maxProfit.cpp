class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int min_price = prices[0];
        int size = prices.size();
        for (int i = 1; i < size; i++) {
            if (prices[i] < min_price) min_price = prices[i];
            else if ((prices[i] - min_price) > max) max = prices[i] - min_price;
        }
        return max;
    }
};