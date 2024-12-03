class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> counter;
        for (char c : text)
            counter[c]++;
        return min({counter['b'], counter['a'], counter['l'] / 2, counter['o'] / 2, counter['n']});
    }
};