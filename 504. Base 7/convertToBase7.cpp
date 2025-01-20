#include <string>
#include <algorithm>

class Solution {
public:
    std::string convertToBase7(int num) {
        if (num == 0)
            return "0";

        bool positive = true;
        std::string res;
        if (num < 0) {
            positive = false;
            num *= -1;
        }

        while (num > 0) {
            res += '0' + num % 7;
            num /= 7;
        }

        if (!positive)
            res += '-';
        std::reverse(res.begin(), res.end());

        return res;
    }
};