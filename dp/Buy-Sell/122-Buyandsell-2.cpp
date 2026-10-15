
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // dp[i][k]: maximum profit from index i
        // k = 0: no transactions left
        // k = 1: can buy
        // k = 2: can sell
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 2; k++) {
                if (k == 2) {
                    // Buy or skip
                    int buy = dp[i + 1][1] - prices[i];
                    int skip = dp[i + 1][2];
                    dp[i][k] = max(buy, skip);
                } else {
                    // Sell or skip
                    int sell = dp[i + 1][2] + prices[i];
                    int skip = dp[i + 1][1];
                    dp[i][k] = max(sell, skip);
                }
            }
        }

        return dp[0][2];
    }
};
