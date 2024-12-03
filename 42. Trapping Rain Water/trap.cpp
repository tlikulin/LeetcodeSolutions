class Solution {
public:
    int trap(vector<int>& height) {
        //initialisation
        int size = static_cast<int>(height.size());
        if (size <= 2) return 0;
        int res = 0;
        int last_processed = -1;
        int max_height_index = -1;
        {int max_height = 0;
        for (int i = 0; i < size; ++i) {
            if (height[i] > max_height) {
                max_height = height[i];
                max_height_index = i;
            }
        }}
        //front propagation
        for (int i = 0; i <= max_height_index; ++i) {
            if (height[i] && (i >= last_processed)) {
                for (int j = i + 1; j <= max_height_index; ++j) {
                    if (height[j] >= height[i]) {
                        for (int e = i + 1; e <= j - 1; ++e)
                            res += height[i] - height[e];
                        last_processed = j;
                        break;
                    }
                }
            }
        }
        //back propagation
        last_processed = size;
        for (int i = size - 1; i >= max_height_index; --i) {
            if (height[i] && (i <= last_processed)) {
                for (int j = i - 1; j >= max_height_index; --j) {
                    if (height[j] >= height[i]) {
                        for (int e = j + 1; e <= i - 1; ++e)
                            res += height[i] - height[e];
                        last_processed = j;
                        break;
                    }
                }
            }
        }
        return res;
    }
};