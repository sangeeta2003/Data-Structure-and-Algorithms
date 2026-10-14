class Solution {
    int fun(int W, vector<int>& val, int n, int i,
            vector<int>& wt, vector<vector<int>>& dp) {

        if (i == n || W == 0) return 0;

        if (dp[i][W] != -1) return dp[i][W];

        int no = fun(W, val, n, i + 1, wt, dp);

        int yes = 0;
        if (wt[i] <= W) {
            yes = val[i] + fun(W - wt[i], val, n, i + 1, wt, dp);
        }

        return dp[i][W] = max(yes, no);
    }

public:
    int knapsack(int W, vector<int>& val, vector<int>& wt) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));

        return fun(W, val, n, 0, wt, dp);
    }
};