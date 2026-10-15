Longest Increasing Subsequence (LIS)

Problem

Find the length of the longest strictly increasing subsequence in an array.

Approach: Dynamic Programming

Initialize res[i] = 1 for every element.

For each index i, check all previous indices j.

If nums[j] < nums[i], update res[i] = max(res[i], res[j] + 1).

Return the maximum value in res.

Complexity

Time: O(n²)

Space: O(n)