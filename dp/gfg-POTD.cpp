class Solution {
  public:
    int minimumStep(int n) {
        vector<int> dp(n + 1, INT_MAX);

                dp[1] = 0;

                for (int i = 1; i < n; i++) {
                    if (dp[i] == INT_MAX) continue;

                    // Edge: i -> i + 1
                    dp[i + 1] = min(dp[i + 1], dp[i] + 1);

                    // Edge: i -> 3 * i
                    if (3 * i <= n) {
                        dp[3 * i] = min(dp[3 * i], dp[i] + 1);
                    }
                }

                return dp[n];
        // code here
        
    }
};