
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        // Find maximum factor and minimum price
        int maxFactor = 0;
        int minPrice = INT_MAX;

        for (auto &item : items) {
            maxFactor = max(maxFactor, item[0]);
            minPrice = min(minPrice, item[1]);
        }

        // Count frequency of each factor
        vector<int> freq(maxFactor + 1, 0);

        for (auto &item : items) {
            freq[item[0]]++;
        }

        // 0/1 Knapsack DP
        vector<int> dp(budget + 1, 0);

        for (auto &item : items) {
            int factor = item[0];
            int price = item[1];

            // First purchase gives itself + all eligible free items
            int gain = 0;

            for (int f = factor; f <= maxFactor; f += factor) {
                gain += freq[f];
            }

            // Each item type can be activated only once
            for (int b = budget; b >= price; b--) {
                dp[b] = max(dp[b], dp[b - price] + gain);
            }
        }

        // Use remaining budget to buy additional copies
        int ans = 0;

        for (int b = 0; b <= budget; b++) {
            ans = max(ans, dp[b] + (budget - b) / minPrice);
        }

        return ans;
    }
};
