#include <vector>
#include <queue>

class Solution {
public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::vector<int> degree(numCourses, 0);
        std::vector<std::vector<int>> graph(numCourses); // prerequisite -> courses

        for (const auto& edge : prerequisites) {
            graph[edge[1]].push_back(edge[0]); 
            degree[edge[0]]++;
        }

        std::queue<int> q;
        std::vector<int> result;
        result.reserve(numCourses);

        for (int i = 0; i < numCourses; i++) {
            if (degree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int course = q.front();
            q.pop();
            result.push_back(course);

            for (int depend : graph[course]) {
                degree[depend]--;
                if (degree[depend] == 0) {
                    q.push(depend);
                }
            }
        }

        if (result.size() == numCourses)
            return result;
        return {};
    }
};