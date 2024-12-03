class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char c : s) {
            if (stk.empty())
                stk.push(c);
            else {
                switch(c) {
                    case '(':
                    case '{':
                    case '[':
                        stk.push(c);
                        break;
                    case ')':
                        if (stk.top() == '(') stk.pop();
                        else return false;
                        break;
                    case '}':
                        if (stk.top() == '{') stk.pop();
                        else return false;
                        break;
                    case ']':
                        if (stk.top() == '[') stk.pop();
                        else return false;
                        break;
                }
            }
        }
        return stk.empty();
    }
};