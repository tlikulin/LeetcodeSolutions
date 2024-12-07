#include <vector>
#include <string>
#include <stack>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> stk;
        int num1; int num2;
        for (const std::string& op : tokens) {
            if (op == "+") {
                num2 = stk.top(); stk.pop();
                num1 = stk.top(); stk.pop();
                stk.push(num1 + num2);
            } else if (op == "-") {
                num2 = stk.top(); stk.pop();
                num1 = stk.top(); stk.pop();
                stk.push(num1 - num2);
            } else if (op == "*") {
                num2 = stk.top(); stk.pop();
                num1 = stk.top(); stk.pop();
                stk.push(num1 * num2);
            } else if (op == "/") {
                num2 = stk.top(); stk.pop();
                num1 = stk.top(); stk.pop();
                stk.push(num1 / num2);
            } else 
                stk.push(stoi(op));
        }
        return stk.top();
    }
};