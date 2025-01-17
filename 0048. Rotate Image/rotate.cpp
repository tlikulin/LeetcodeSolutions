#include <vector>
#include <algorithm>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int size = matrix.size();
        for (int it = 0; it < size / 2; it++) {
            for (int i = 0; i < size - 1 - 2 * it; i++) {
                std::swap(matrix[it][it + i], matrix[size - 1 - it][size - 1 - it - i]);
                std::swap(matrix[it][it + i], matrix[size - 1 - it - i][it]);
                std::swap(matrix[it + i][size - 1 - it], matrix[size - 1 - it][size - 1 - it - i]);
            }
        }
    }
};