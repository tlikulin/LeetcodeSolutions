#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int rows = static_cast<int>(matrix.size());
        int columns = static_cast<int>(matrix[0].size());
        int left = 0;
        int right = rows * columns - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int mid_element = matrix[mid / columns][mid % columns];
            if (mid_element == target)
                return true;
            if (mid_element > target)
                right = mid - 1;
            else
                left = mid + 1; 
        }
        return false;
    }
};