#include <vector>
#include <queue>

class Solution {
public:
    int networkDelayTime(std::vector<std::vector<int>>& times, int n, int k) {
        std::vector<std::vector<std::pair<int, int>>> adjacencyList(n);
        for (auto& travel : times) {
            adjacencyList[travel[0]-1].emplace_back(travel[1]-1, travel[2]);
        }

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> minHeap; // (time, node)
        minHeap.emplace(0, k-1);

        int toVisit = n;
        int worstTime = 0;
        std::vector<bool> visited(n, false);

        while (toVisit > 0 && !minHeap.empty()) {
            auto [time, node] = minHeap.top();
            minHeap.pop();

            if (!visited[node]) {   
                visited[node] = true;
                toVisit--;
                if (time > worstTime)
                    worstTime = time;
                for (auto [nextNode, dTime] : adjacencyList[node]) {
                    if (!visited[nextNode])
                        minHeap.emplace(time+dTime, nextNode);
                }
            }
        }
        
        return toVisit == 0 ? worstTime : -1;
    }
};