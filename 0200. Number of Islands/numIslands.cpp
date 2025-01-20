#include <array>
#include <vector>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        constexpr std::array<std::pair<int, int>, 4> directions {{ {0, -1}, {1, 0}, {0, 1}, {-1, 0} }};

        int m = (int)grid.size();
        int n = (int)grid[0].size();
        int ans = 0;

        for (int iy = 0; iy < m; iy++) {
            for (int ix = 0; ix < n; ix++) {
                if (grid[iy][ix] == '1') {
                    ans++;
                    destroyIsland(ix, iy, grid, m, n, directions);
                }
            }
        }

        return ans;
    }

    void destroyIsland (int p_x, int p_y, std::vector<std::vector<char>>& grid, int m, int n, const auto& directions) {
            if (p_x < 0 || p_x >= n || p_y < 0 || p_y >= m || grid[p_y][p_x] == '0')
                return;

            grid[p_y][p_x] = '0';

            for (auto [dx, dy] : directions) {
                destroyIsland(p_x+dx, p_y+dy, grid, m, n, directions);
            }
    }
};