#include <string>
#include <algorithm>

class Solution {
public:
    std::string addBinary(std::string& a, std::string& b) {
        int i = (int)a.size();
        int j = (int)b.size();

        std::string res;
        res.reserve(std::max(i, j) + 1);

        bool carry = 0;
        --i, --j;
        while (i >= 0 || j >= 0 || carry) {
            bool bit1 = (i >= 0) ? a[i] - '0' : 0;
            bool bit2 = (j >= 0) ? b[j] - '0' : 0;

            int sum = bit1 + bit2 + carry;
            carry = sum / 2;
            res += '0' + (sum % 2);
            --i, --j;
        }

        std::reverse(res.begin(), res.end());
        return res;
    }
};