#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        int size = static_cast<int>(temperatures.size());
        std::vector<int> res(size, 0);
        std::stack<int> stk;
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