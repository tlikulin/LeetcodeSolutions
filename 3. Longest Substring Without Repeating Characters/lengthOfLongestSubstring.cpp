// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         auto n = static_cast<int>(s.size());
//         int L = 0; int R;
//         int maxLength = 0;
//         unordered_set<char> hshtbl;
//         for (R = 0; R < n; ++R) {
//             char c = s[R];
//             if (!hshtbl.insert(c).second) {
//                 maxLength = max(maxLength, R - L);
//                 while (s[L] != c) {
//                     hshtbl.erase(s[L]);
//                     ++L;
//                 }
//                 ++L;
//             }
//         }
//         maxLength = max(maxLength, R - L);
//         return maxLength;
//     }
// };

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        auto n = static_cast<int>(s.size());
        int L = 0; int R;
        int maxLength = 0;
        array<bool, CHAR_MAX+1> alreadyHas = {false};
        for (R = 0; R < n; ++R) {
            char c = s[R];
            if (alreadyHas[c]) {
                maxLength = max(maxLength, R - L);
                while (s[L] != c) {
                    alreadyHas[s[L]] = false;
                    ++L;
                }
                ++L;
            } else
                alreadyHas[c] = true;
        }
        maxLength = max(maxLength, R - L);
        return maxLength;
    }
};