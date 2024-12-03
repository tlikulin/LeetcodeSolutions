class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int L = 1;
        int R = *max_element(piles.begin(), piles.end());  
        while (L < R) {
            int M = L + (R - L) / 2;
            int timeNeeded = 0;
            for (int const& i : piles)
                timeNeeded += i % M ? i / M + 1 : i / M;
            if (timeNeeded > h)
                L = M + 1;
            else
                R = M;
        }
        return L;
    }
};