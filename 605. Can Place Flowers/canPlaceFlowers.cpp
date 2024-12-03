class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (!n) return true;
        auto size = static_cast<int>(flowerbed.size());
        for (int i = 0; i < size; ++i) {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == size - 1 || flowerbed[i+1] == 0)) {
                --n;
                ++i;
            }
            if (n == 0) return true;
        }
        return false;
    }
};