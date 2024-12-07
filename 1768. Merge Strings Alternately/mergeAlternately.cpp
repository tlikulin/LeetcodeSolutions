#include <string>
#include <algorithm>

class Solution {
public:
    std::string mergeAlternately(std::string word1, std::string word2) {
        bool swapped = false;
        if (word1.size() > word2.size()) {
            std::swap(word1, word2);
            swapped = true;
        }

        std::string ans;
        if (!swapped){
            for (int i = 0; i < word1.size(); i++) {
                ans.push_back(word1[i]);
                ans.push_back(word2[i]);
            }
        } else {
            for (int i = 0; i < word1.size(); i++) {
                ans.push_back(word2[i]);
                ans.push_back(word1[i]);
            }
        }   
        ans.append(word2, word1.size());
        return ans;
    }
};