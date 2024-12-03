class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int num1; int num2;
        for (string const& op : tokens) {
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