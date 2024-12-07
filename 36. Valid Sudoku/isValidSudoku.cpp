#include <vector>
#include <unordered_set>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::unordered_set<char> hash;
        char item;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                item = board[i][j];
                if (item != '.' && !hash.insert(item).second)
                    return false;
            }
            hash.clear();
        }
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                item = board[j][i];
                if (item != '.' && !hash.insert(item).second)
                    return false;
            }
            hash.clear();
        }
        for (int x = 0; x < 3; ++x) {
            for (int y = 0; y < 3; ++y) {
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        item = board[x * 3 + i][y * 3 + j];
                        if (item != '.' && !hash.insert(item).second)
                            return false;
                     }
                }
                hash.clear();
            }
        }
        return true;
    }
};