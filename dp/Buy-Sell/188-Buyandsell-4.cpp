
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int actions = 2 * k;

        vector<vector<int>> dp(n + 1, vector<int>(actions + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= actions; j++) {
                if (j % 2 == 0) {
                    // Buy
                    int buy = dp[i + 1][j - 1] - prices[i];
                    int skip = dp[i + 1][j];
                    dp[i][j] = max(buy, skip);
                } else {
                    // Sell
                    int sell = dp[i + 1][j - 1] + prices[i];
                    int skip = dp[i + 1][j];
                    dp[i][j] = max(sell, skip);
                }
            }
        }

        return dp[0][actions];
    }
};
