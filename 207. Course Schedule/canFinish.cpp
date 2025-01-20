#include <vector>

class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::vector<std::vector<int>> adjacencyList(numCourses);
        for (const auto& edge : prerequisites) {
            adjacencyList[edge[0]].push_back(edge[1]);
        }

        std::vector<char> states(numCourses, 0); // 0 - Default, 1 - Visiting now, 2 - Already visited
        for (int i = 0; i < numCourses; i++) {
            if (!DFS(i, adjacencyList, states))
                return false;
        }

        return true;
    }

private:
    bool DFS(int node, std::vector<std::vector<int>>& adjacencyList, std::vector<char>& states) {
        if (states[node] == 1)
            return false;
        if (states[node] == 2)
            return true;

        states[node] = 1;
        for (int prereq : adjacencyList[node]) {
            if (!DFS(prereq, adjacencyList, states))
                return false;
        }

        states[node] = 2;
        return true;
    }
};