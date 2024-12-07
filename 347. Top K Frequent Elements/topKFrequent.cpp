#include <vector>
#include <queue>
#include <unordered_map>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> counter;
        for (int i : nums) ++counter[i];

        auto myCmp = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {return a.second > b.second;};
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(myCmp)> minHeap(myCmp);

        for (auto& entry : counter) {
            minHeap.push(move(entry));
            if (minHeap.size() > k) minHeap.pop();
        }

        std::vector<int> res;
        while (!minHeap.empty()) {
            res.push_back(minHeap.top().first);
            minHeap.pop();
        }

        return res;
    }
};