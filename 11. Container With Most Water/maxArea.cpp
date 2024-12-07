#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int max_water = 0;
        int L = 0;
        int R = static_cast<int>(height.size()) - 1;
        while (L < R) {
            max_water = std::max(max_water, (R - L) * std::min(height[L], height[R]));
            if (height[L] < height[R])
                ++L;
            else
                --R;
        }
        return max_water;
    }
};