#include <string>
#include <unordered_map>

class Solution {
public:
    bool canConstruct(std::string& ransomNote, std::string& magazine) {
        std::unordered_map<char, int> source, target;
        for (char c = 97; c <= 122; c++) {
            source[c] = 0;
            target[c] = 0;
        }

        for (auto c : magazine) {
            source[c] += 1;
        }
        for (auto c : ransomNote) {
            target[c] += 1;
        }

        for (char c = 97; c <= 122; c++)
            if (source[c] < target[c])
                return false;
        return true;
    }
};