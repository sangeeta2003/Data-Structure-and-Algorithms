# 455. Assign Cookies

## Approach: Greedy + Two Pointers

1. Sort the greed factors `g` and cookie sizes `s` in ascending order.
2. Use two pointers: `i` for children and `j` for cookies.
3. If `s[j] >= g[i]`, assign the cookie and increment both pointers and the result.
4. Otherwise, move to the next cookie because it is too small.
5. Return the maximum number of content children.

## Complexity Analysis

* **Time:** `O(n log n + m log m)` for sorting.
* **Space:** `O(1)` auxiliary space, excluding sorting implementation details.

## Key Concept

Greedy strategy: Give each child the smallest cookie that satisfies their greed, saving larger cookies for children who need them.
