class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water = 0;
        int L = 0;
        int R = static_cast<int>(height.size()) - 1;
        while (L < R) {
            max_water = max(max_water, (R - L) * min(height[L], height[R]));
            if (height[L] < height[R])
                ++L;
            else
                --R;
        }
        return max_water;
    }
};