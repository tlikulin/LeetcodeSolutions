class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        bool swapped = false;
        if (word1.size() > word2.size()) {
            swap(word1, word2);
            swapped = true;
        }

        string ans;
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