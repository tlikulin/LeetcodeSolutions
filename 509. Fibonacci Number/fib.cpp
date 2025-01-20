class Solution {
public:
    int fib(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        
        int prev = 0, curr = 1;
        for (int i = 2; i <= n; i++) {
            curr = curr + prev;
            prev = curr - prev;
        }
        return curr;
    }
};