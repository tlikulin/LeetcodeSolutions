#include <vector>
#include <queue>
#include <cmath>

class Solution {
public:
    int minCostConnectPoints(std::vector<std::vector<int>>& points) {
        int n = (int)points.size();
        std::vector<bool> seen(n, false);

        auto cmpDist = [] (std::pair<int, int>& p1, std::pair<int, int>& p2) { return p1.first > p2.first; };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmpDist)> minHeap(cmpDist); // (dist, pointIndex)
        minHeap.emplace(0, 0);

        int cost = 0;
        int added = 0;

        while (added < n) {
            std::pair<int, int> candidate = minHeap.top();
            minHeap.pop();

            if (seen[candidate.second])
                continue;
            
            seen[candidate.second] = true;
            added++;
            cost += candidate.first;

            for (int i = 1; i < n; i++) {
                if (!seen[i]) {
                    minHeap.emplace(manhattanDistance(points[i], points[candidate.second]), i);
                }
            }
        }

        return cost;
    }

    int manhattanDistance(const std::vector<int>& point1, const std::vector<int>& point2) {
        return abs(point2[0]-point1[0]) + abs(point2[1]-point1[1]);
    }
};