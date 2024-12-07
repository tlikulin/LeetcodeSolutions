#include <vector>
#include <algorithm>

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        int L = 0;
        int R = s.size() - 1;

        while (L < R) {
            std::swap(s[L], s[R]);
            ++L;
            --R;
        } 
    }
};