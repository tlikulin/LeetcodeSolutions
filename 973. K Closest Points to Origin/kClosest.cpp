#include <vector>
#include <queue>

class Solution {
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
        auto cmpDist = [] (const std::vector<int>& p1, const std::vector<int>& p2) 
            {return p1[0]*p1[0] + p1[1]*p1[1] > p2[0]*p2[0] + p2[1]*p2[1];};
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(cmpDist)> minHeap(cmpDist);
        for (const auto& point : points) minHeap.push(point);

        std::vector<std::vector<int>> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(minHeap.top());
            minHeap.pop();
        }

        return res;
    }
};