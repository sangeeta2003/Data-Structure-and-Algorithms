## LCS Workflow (Longest Common Subsequence)

1. Take two strings: `text1` and `text2`.
2. Create a 2D DP table of size `(n+1) × (m+1)` and initialize it with `0`.
3. Traverse both strings from right to left.
4. If `text1[i] == text2[j]`, set `dp[i][j] = 1 + dp[i+1][j+1]`.
5. Otherwise, set `dp[i][j] = max(dp[i][j+1], dp[i+1][j])`.
6. Return `dp[0][0]`, which gives the length of the LCS.

Example: `text1 = "abcde"`, `text2 = "ace"`

The LCS is `"ace"`, so the answer is `3`.

