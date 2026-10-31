class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        const int MOD = 1e9 + 7;

        vector<vector<long long>> right(m, vector<long long>(n, 0));
        vector<vector<long long>> down(m, vector<long long>(n, 0));

        // Starting position
        right[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // If current cell is a mirror
                if (grid[i][j] == 1) {

                    // Entered from left, redirect down
                    if (i + 1 < m) {
                        down[i + 1][j] =
                            (down[i + 1][j] + right[i][j]) % MOD;
                    }

                    // Entered from above, redirect right
                    if (j + 1 < n) {
                        right[i][j + 1] =
                            (right[i][j + 1] + down[i][j]) % MOD;
                    }

                }
                else {

                    // Empty cell: combine incoming paths
                    long long ways = (right[i][j] + down[i][j]) % MOD;

                    // Move right
                    if (j + 1 < n) {
                        right[i][j + 1] =
                            (right[i][j + 1] + ways) % MOD;
                    }

                    // Move down
                    if (i + 1 < m) {
                        down[i + 1][j] =
                            (down[i + 1][j] + ways) % MOD;
                    }
                }
            }
        }

        return (right[m - 1][n - 1] +
                down[m - 1][n - 1]) % MOD;
    }
};