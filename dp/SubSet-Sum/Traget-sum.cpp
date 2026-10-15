
class Solution {
  public:
    int totalWays(vector<int>& arr, int target) {
        int n = arr.size();
        int totalSum = 0;

        for (int x : arr) {
            totalSum += x;
        }

        if (abs(target) > totalSum) return 0;
        if ((totalSum + target) % 2 != 0) return 0;

        int sum = (totalSum + target) / 2;

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

        // One way to make sum 0: choose no elements
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= sum; j++) {
                dp[i][j] = dp[i + 1][j];

                if (arr[i] <= j) {
                    dp[i][j] += dp[i + 1][j - arr[i]];
                }
            }
        }

        return dp[0][sum];
    }
};