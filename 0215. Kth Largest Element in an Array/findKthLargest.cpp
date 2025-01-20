#include <queue>
#include <vector>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int> maxHeap (nums.begin(), nums.end());

        while (k > 1) {
            maxHeap.pop();
            --k;
        }

        return maxHeap.top();
    }
};