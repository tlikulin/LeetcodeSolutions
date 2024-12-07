#include <vector>
#include <string>
#include <array>

class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        size_t m = board.size();
        size_t n = board[0].size();
        size_t length = word.size();

        bool found = false;
        std::vector<std::vector<bool>> used(m, std::vector<bool>(n, false));
        std::array<std::pair<int, int>, 4> directions = {std::make_pair(-1, 0), std::make_pair(0, -1), std::make_pair(1, 0), std::make_pair(0, 1)};
        for (int i = 0; i < m && !found; ++i) {
            for (int j = 0; j < n && !found; ++j) {
                if (board[i][j] == word[0]) {
                    used[i][j] = true;
                    exist_backtrack(board, word, length, 1, found, directions, j, i, m, n, used);
                    used[i][j] = false;
                }
            }
        }

        return found;
    }

    void exist_backtrack(auto& board, std::string& word, int length, int count, bool& found, auto& directions, int x, int y, int m, int n, auto& used) {
        if (count == length) {
            found = true;
            return;
        }

        for (auto direction : directions) {
            int x_next = x + direction.first;
            int y_next = y + direction.second;

            if (0 <= x_next && x_next < n && 0 <= y_next && y_next < m && board[y_next][x_next] == word[count] && !used[y_next][x_next]) {
                used[y_next][x_next] = true;
                exist_backtrack(board, word, length, count+1, found, directions, x_next, y_next, m, n, used);
                used[y_next][x_next] = false;
            }

            if (found) return;
        }
    }
};