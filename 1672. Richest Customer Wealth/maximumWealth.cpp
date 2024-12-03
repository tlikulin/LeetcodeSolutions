class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int current_max = 0;

        for (vector<int> customer : accounts) {
            int wealth = 0;
            for (int bank : customer) {
                wealth += bank;
            }
            if (wealth > current_max) current_max = wealth;
        }

        return current_max;
    }
};