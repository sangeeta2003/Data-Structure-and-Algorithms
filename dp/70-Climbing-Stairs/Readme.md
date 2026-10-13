# Climbing Stairs — LeetCode 70

## Approach: Recursion + Memoization (Top-Down DP)

* If `i == n`, return `1` because we reached the destination.
* If `i > n`, return `0` because we exceeded the destination.
* Check whether the result for step `i` is already stored in `dp`.
* Recursively calculate ways by taking either 1 step or 2 steps.
* Store `dp[i] = a1 + a2` and return the result.
* Pass `dp` by reference to avoid copying the map during recursion.

## Complexity

* **Time:** O(n)
* **Space:** O(n)
