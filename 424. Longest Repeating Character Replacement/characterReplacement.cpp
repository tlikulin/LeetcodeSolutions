class Solution {
public:
    int characterReplacement(string s, int k) {
        auto n = static_cast<int>(s.size());
        int L = 0;
        int maxLen = 0;
        int domCount = 0;
        array<int, 'Z'-'A'+1> counter = {0};

        for (int R = 0; R < n; ++R) {
            char c = s[R];
            domCount = max(domCount, ++counter[c-'A']);

            while ((R-L+1) - domCount > k) {
                --counter[s[L]-'A'];
                ++L;
            }

            maxLen = max(maxLen, R-L+1);
        }
        return maxLen;
    }
};