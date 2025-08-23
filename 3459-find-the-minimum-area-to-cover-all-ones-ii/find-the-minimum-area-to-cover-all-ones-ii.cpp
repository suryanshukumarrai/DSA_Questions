class Solution {
public:
    int Cal(vector<vector<int>>& grid, int sx, int ex, int sy, int ey) {
        int minX = 1e6, maxX = -1e6, minY = 1e6, maxY = -1e6;
        for (int i = sx; i <= ex; i++) {
            for (int j = sy; j <= ey; j++) {
                if (grid[i][j] == 1) {
                    minX = min(minX, i);
                    maxX = max(maxX, i);
                    minY = min(minY, j);
                    maxY = max(maxY, j);
                }
            }
        }
        if (minX > maxX || minY > maxY)
            return 0;
        return (maxX - minX + 1) * (maxY - minY + 1);
    }

    int minimumSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int mini = 1e9;

        // all vertical
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m - 1; j++) {
                int a1 = Cal(grid, 0, n - 1, 0, i);
                int a2 = Cal(grid, 0, n - 1, i + 1, j);
                int a3 = Cal(grid, 0, n - 1, j + 1, m - 1);
                mini = min(mini, a1 + a2 + a3);
            }
        }

        // all horizontal
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int a1 = Cal(grid, 0, i, 0, m - 1);
                int a2 = Cal(grid, i + 1, j, 0, m - 1);
                int a3 = Cal(grid, j + 1, n - 1, 0, m - 1);
                mini = min(mini, a1 + a2 + a3);
            }
        }

        // up and down split
        for (int i = 0; i < n - 1; i++) {
            int a1 = Cal(grid, 0, i, 0, m - 1);
            for (int j = 0; j < m - 1; j++) {
                int a2 = Cal(grid, i + 1, n - 1, 0, j);
                int a3 =
                    Cal(grid, i + 1, n - 1, j + 1, m - 1); 
                mini = min(mini, a1 + a2 + a3);
            }
        }

        // up split and down
        for (int i = 0; i < n - 1; i++) {
            int a1 = Cal(grid, i + 1, n - 1, 0, m - 1);
            for (int j = 0; j < m - 1; j++) {
                int a2 = Cal(grid, 0, i, 0, j);
                int a3 = Cal(grid, 0, i, j + 1, m - 1); 
                mini = min(mini, a1 + a2 + a3);
            }
        }

        // left and split right
        for (int i = 0; i < m - 1; i++) {
            int a1 = Cal(grid, 0, n - 1, 0, i);
            for (int j = 0; j < n - 1; j++) {
                int a2 = Cal(grid, 0, j, i + 1, m - 1);
                int a3 = Cal(grid, j + 1, n - 1, i + 1, m - 1);
                mini = min(mini, a1 + a2 + a3);
            }
        }

        // left split and right
        for (int i = 0; i < m - 1; i++) {
            int a1 = Cal(grid, 0, n - 1, i + 1, m - 1);
            for (int j = 0; j < n - 1; j++) {
                int a2 = Cal(grid, 0, j, 0, i);
                int a3 = Cal(grid, j + 1, n - 1, 0, i);
                mini = min(mini, a1 + a2 + a3);
            }
        }

        return mini;
    }
};