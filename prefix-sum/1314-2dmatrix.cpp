
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));

        // Step 1: Build 2D Prefix Sum
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                prefix[i + 1][j + 1] =
                    mat[i][j]
                    + prefix[i][j + 1]
                    + prefix[i + 1][j]
                    - prefix[i][j];
            }
        }

        // Step 2: Calculate each block sum
        vector<vector<int>> ans(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int r1 = max(0, i - k);
                int c1 = max(0, j - k);

                int r2 = min(m - 1, i + k);
                int c2 = min(n - 1, j + k);

                ans[i][j] =
                    prefix[r2 + 1][c2 + 1]
                    - prefix[r1][c2 + 1]
                    - prefix[r2 + 1][c1]
                    + prefix[r1][c1];
            }
        }

        return ans;
    }
};
