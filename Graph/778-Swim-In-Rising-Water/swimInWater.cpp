class Solution {
    bool dfs(vector<vector<int>>& grid, int n, int m, int time,
             int i, int j, vector<vector<bool>>& vis) {

        if (i < 0 || i >= n || j < 0 || j >= m ||
            vis[i][j] || grid[i][j] > time) {
            return false;
        }

        if (i == n - 1 && j == m - 1) {
            return true;
        }

        vis[i][j] = true;

        return dfs(grid, n, m, time, i + 1, j, vis) ||
               dfs(grid, n, m, time, i - 1, j, vis) ||
               dfs(grid, n, m, time, i, j + 1, vis) ||
               dfs(grid, n, m, time, i, j - 1, vis);
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int low = grid[0][0];
        int high = grid[0][0];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                high = max(high, grid[i][j]);
            }
        }

        int res = high;

        while (low <= high) {
            int guess = low + (high - low) / 2;

            vector<vector<bool>> vis(n, vector<bool>(m, false));

            if (dfs(grid, n, m, guess, 0, 0, vis)) {
                res = guess;
                high = guess - 1;
            } else {
                low = guess + 1;
            }
        }

        return res;
    }
};