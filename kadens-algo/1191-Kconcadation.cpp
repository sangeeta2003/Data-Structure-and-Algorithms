#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long MOD = 1e9 + 7;

    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n = arr.size();
        long long tot = 0;
        for (auto x : arr) tot += x;

        // 1. Kadane's algorithm for single array
        long long sum = 0, best = 0;
        for (int i = 0; i < n; i++) {
            sum = max((long long)arr[i], sum + arr[i]);
            best = max(best, sum);
        }
        long long ans = best;

        // 2. Prefix max
        long long prefix = 0, maxPrefix = 0;
        for (int i = 0; i < n; i++) {
            prefix += arr[i];
            maxPrefix = max(maxPrefix, prefix);
        }

        // 3. Suffix max
        long long suffix = 0, maxSuffix = 0;
        for (int i = n - 1; i >= 0; i--) {
            suffix += arr[i];
            maxSuffix = max(maxSuffix, suffix);
        }

        // 4. If k >= 2, check across multiple concatenations
        if (k >= 2) {
            ans = max(ans, maxSuffix + maxPrefix);
            ans = max(ans, maxSuffix + tot * (k - 2) + maxPrefix);
        }

        return ans % MOD;
    }
};

// Why k - 2?

// Because:
// - One copy contributes the suffix.
// - One copy contributes the prefix.
// - The remaining k - 2 copies contribute their complete array sum.
// This code finds the maximum subarray sum from an array repeated `k` times, without actually creating the repeated array.

// It:

// 1. Calculates the total sum of one array.
// 2. Uses Kadane’s algorithm to find the maximum subarray sum in one copy.
// 3. Finds the maximum prefix and suffix sums.
// 4. Checks the best subarray crossing between copies.
// 5. Uses the total sum of middle copies when `k > 2`.
// 6. Returns the maximum result modulo \\(10^9+7\\).

// Time: O(n) | Space: O(1)