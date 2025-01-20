#include <vector>
#include <queue>

class Solution {
public:
    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights) {
        int m = (int)heights.size();
        int n = (int)heights[0].size();
        int numCells = m * n;
        std::vector<std::vector<int>> res;

        // (y, x) -> y * n + x
        std::vector<bool> canPacific(numCells, false);
        std::vector<bool> canAtlantic(numCells, false);
        std::queue<int> q;

        // CHECKING FOR PACIFIC
        for (int y = 0; y < m; y++) {
            q.push(y * n); // left column
            canPacific[y * n] = true;
        }
        for (int x = 1; x < n; x++) {
            q.push(x); // top row
            canPacific[x] = true;
        }

        while (!q.empty()) {
            int cell = q.front();
            q.pop();

            if (cell % n != 0 && cell - 1 >= 0 && !canPacific[cell - 1] &&
                heights[(cell - 1) / n][(cell - 1) % n] >=
                heights[cell / n][cell % n]) { // try go left

                canPacific[cell - 1] = true;
                q.push(cell - 1);
            }
            if ((cell + 1) % n != 0 && cell + 1 < numCells && !canPacific[cell + 1] &&
                heights[(cell + 1) / n][(cell + 1) % n] >=
                heights[cell / n][cell % n]) { // try go right

                canPacific[cell + 1] = true;
                q.push(cell + 1);
            }
            if (cell - n >= 0 && !canPacific[cell - n] &&
                heights[(cell - n) / n][(cell - n) % n] >=
                heights[cell / n][cell % n]) { // try go up

                canPacific[cell - n] = true;
                q.push(cell - n);
            }
            if (cell + n < numCells && !canPacific[cell + n] &&
                heights[(cell + n) / n][(cell + n) % n] >=
                heights[cell / n][cell % n]) { // try go down

                canPacific[cell + n] = true;
                q.push(cell + n);
            }
        }

        // CHECKING FOR ATLANTIC
        for (int y = 0; y < m; y++) {
            q.push(y * n + n - 1); // right column
            canAtlantic[y * n + n - 1] = true;
        }
        for (int x = 0; x < n - 1; x++) {
            q.push((m - 1) * n + x); // bottom row
            canAtlantic[(m - 1) * n + x] = true;
        }

        while (!q.empty()) {
            int cell = q.front();
            q.pop();

            if (cell % n != 0 && cell - 1 >= 0 && !canAtlantic[cell - 1] &&
                heights[(cell - 1) / n][(cell - 1) % n] >=
                heights[cell / n][cell % n]) { // try go left

                canAtlantic[cell - 1] = true;
                q.push(cell - 1);
            }
            if ((cell + 1) % n != 0 && cell + 1 < numCells && !canAtlantic[cell + 1] &&
                heights[(cell + 1) / n][(cell + 1) % n] >=
                heights[cell / n][cell % n]) { // try go right

                canAtlantic[cell + 1] = true;
                q.push(cell + 1);
            }
            if (cell - n >= 0 && !canAtlantic[cell - n] &&
                heights[(cell - n) / n][(cell - n) % n] >=
                heights[cell / n][cell % n]) { // try go up

                canAtlantic[cell - n] = true;
                q.push(cell - n);
            }
            if (cell + n < numCells && !canAtlantic[cell + n] &&
                heights[(cell + n) / n][(cell + n) % n] >=
                heights[cell / n][cell % n]) { // try go down

                canAtlantic[cell + n] = true;
                q.push(cell + n);
            }
        }

        for (int cell = 0; cell < numCells; cell++) {
            if (canPacific[cell] && canAtlantic[cell])
                res.push_back({cell / n, cell % n});
        }

        return res;
    }
};