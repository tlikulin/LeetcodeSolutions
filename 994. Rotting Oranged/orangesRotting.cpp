#include <vector>
#include <queue>

// (y, x) -> y*n + x
class Solution {
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        int m  = (int)grid.size();
        int n  = (int)grid[0].size();
        int minutes = 0;
        int freshLeft = 0;

        std::queue<int> q;
        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                if (grid[y][x] == 2)
                    q.push(y*n+x);
                else if (grid[y][x] == 1)
                    freshLeft++;
            }
        }

        if (q.empty()) {
            return freshLeft == 0 ? 0 : -1;
        }

        q.push(-1); // -1 means new minute

        while (!q.empty()) {
            int rotten = q.front();
            q.pop();

            if (rotten == -1) {
                if (q.empty()) {
                    return freshLeft == 0 ? minutes : -1; // actual return
                } else {
                    q.push(-1);
                    minutes++;
                }
            } else {
                if (rotten % n != 0 && rotten - 1 >= 0 && grid[(rotten - 1) / n][(rotten - 1) % n] == 1) { // left
                    grid[(rotten - 1) / n][(rotten - 1) % n] = 2;
                    q.push(rotten - 1);
                    freshLeft--;
                }
                if ((rotten + 1) % n != 0 && rotten + 1 < m*n && grid[(rotten + 1) / n][(rotten + 1) % n] == 1) { // right
                    grid[(rotten + 1) / n][(rotten + 1) % n] = 2;
                    q.push(rotten + 1);
                    freshLeft--;
                }
                if (rotten - n >= 0 && grid[(rotten - n) / n][(rotten - n) % n] == 1) { // up
                    grid[(rotten - n) / n][(rotten - n) % n] = 2;
                    q.push(rotten - n);
                    freshLeft--;
                }
                if (rotten + n < m*n && grid[(rotten + n) / n][(rotten + n) % n] == 1) { // down
                    grid[(rotten + n) / n][(rotten + n) % n] = 2;
                    q.push(rotten + n);
                    freshLeft--;
                }
            }
        }

        return -1; // never gonna reach, just for compliance
    }
};