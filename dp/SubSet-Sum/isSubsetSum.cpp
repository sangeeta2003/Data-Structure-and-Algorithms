
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

        // A sum of 0 is always possible: choose an empty subset
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        // Fill the DP table
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= sum; j++) {
                if (arr[i] > j) {
                    dp[i][j] = dp[i + 1][j];
                } else {
                    dp[i][j] = dp[i + 1][j - arr[i]] ||
                               dp[i + 1][j];
                }
            }
        }

        return dp[0][sum];
    }
};