#include <ranges>

class Solution {
public:
    int uniquePaths(int m, int n) {
        //actually finding (m+n-2)C(n-1)
        m--, n--;

        long res = 1;
        for (int i = 1; i <= n; i++) {
            res *= m + i;
            res /= i;
        }

        return res;
    }
};