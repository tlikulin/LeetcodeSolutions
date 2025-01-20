#include <string>
#include <vector>

class Solution {
public:
    int longestCommonSubsequence(std::string& text1, std::string& text2) {
        int n = (int)text1.size(), m = (int)text2.size();
        std::vector<int> prevRow(n+1, 0), currRow(n+1, 0);

        for (int j = 1; j <= m; j++) {
            for (int i = 1; i <= n; i++) {
                if (text1[i-1] == text2[j-1])
                    currRow[i] = 1 + prevRow[i-1];
                else
                    currRow[i] = std::max(currRow[i-1], prevRow[i]);
            }
            prevRow = currRow;
        }

        return currRow[n];
    }
};