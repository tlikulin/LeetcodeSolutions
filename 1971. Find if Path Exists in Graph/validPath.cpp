#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>


class Solution {
public:
    bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination) {
        std::unordered_map<int, std::vector<int>> connections;
        for (const auto& edge : edges) {
            connections[edge[0]].push_back(edge[1]);
            connections[edge[1]].push_back(edge[0]);
        }

        std::unordered_set<int> seen{source};
        std::queue<int> q;
        q.push(source);

        while (!q.empty()) {
            int vertex = q.front();
            q.pop();

            if (vertex == destination) return true;

            for (int conn : connections[vertex]) {
                if (!seen.contains(conn)) {
                    seen.insert(conn);
                    q.push(conn);
                }
            }
        }

        return false;
    }
};