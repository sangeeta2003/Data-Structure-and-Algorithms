
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n + 1, vector<int>(5, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {
                if (k % 2 == 0) {
                    // Buy
                    int buy = dp[i + 1][k - 1] - prices[i];
                    int skip = dp[i + 1][k];
                    dp[i][k] = max(buy, skip);
                } else {
                    // Sell
                    int sell = dp[i + 1][k - 1] + prices[i];
                    int skip = dp[i + 1][k];
                    dp[i][k] = max(sell, skip);
                }
            }
        }

        return dp[0][4];
    }
};
