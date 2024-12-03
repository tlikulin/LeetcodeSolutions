class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = static_cast<int>(temperatures.size());
        vector<int> res(size, 0);
        stack<int> stk;
        for (int i = 0; i < size; ++i) {
            while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                    res[stk.top()] = i - stk.top();
                    stk.pop();
                }
            stk.push(i);
        }
        return res;
    }
};