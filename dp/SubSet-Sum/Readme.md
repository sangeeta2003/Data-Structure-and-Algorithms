# Subset Sum Problem — Dynamic Programming Workflow

## 1. Problem Statement

Given an array of positive integers and a target sum, determine whether a subset exists whose elements add up exactly to the target sum.

**Example:**

* Array: `[3, 34, 4, 12, 5, 2]`
* Target Sum: `9`
* Output: `true`

**Explanation:** The subset `{3, 4, 2}` adds up to `9`.

## 2. Approach: Bottom-Up Dynamic Programming

For each element, we have two choices:

1. **Take the element:** If it does not exceed the remaining target, include it in the subset.
2. **Skip the element:** Ignore it and continue with the remaining elements.

If either choice can produce the target sum, the result is `true`.

## 3. DP State

`dp[i][j]` represents whether it is possible to form sum `j` using elements from index `i` to the end of the array.

* Rows represent array indices.
* Columns represent possible target sums.
* Each cell stores either `true` or `false`.

## 4. Base Cases

* **Target sum = 0:** Always possible by selecting an empty subset.
* **No elements remaining:** A positive target sum cannot be formed.

## 5. Workflow

1. Create a DP table with rows for all array indices, including an extra row for when no elements remain, and columns for sums from `0` to the target.
2. Initialize all states as `false`.
3. Mark the sum-zero state as `true` for every index.
4. Start processing the array from the last element toward the first.
5. For every element, consider each target sum from `1` to the required sum.
6. If the current element is greater than the target, skip it and use the result from the next index.
7. Otherwise, check two possibilities: take the element and solve the remaining sum, or skip it and keep the target unchanged.
8. Mark the current state `true` if either possibility succeeds.
9. After filling the table, check whether the target sum is possible starting from index `0`.

## 6. Dry Run

Consider:

* Array: `[3, 4, 2]`
* Target Sum: `9`

Process the elements from right to left.

**Step 1: Element = 2**

* We can form sum `2` using `{2}`.
* Other sums greater than `2` cannot be formed using this element alone.

**Step 2: Element = 4**

* We can form sum `4` using `{4}`.
* We can form sum `6` using `{4, 2}`.
* Sum `2` remains possible using `{2}`.

**Step 3: Element = 3**

* We can form sum `3` using `{3}`.
* We can form sum `5` using `{3, 2}`.
* We can form sum `7` using `{3, 4}`.
* We can form sum `9` using `{3, 4, 2}`.

Therefore, the target sum `9` is possible.

**Final Output:** `true`

## 7. Complexity Analysis

* **Time Complexity:** O(n × sum), because each DP state is calculated once.
* **Space Complexity:** O(n × sum), because the DP table stores results for each index and target sum.

Here, `n` is the number of elements in the array.

## 8. Key Takeaway

Subset Sum is a classic **0/1 Knapsack Dynamic Programming** problem. At every step, decide whether to take or skip the current element. Each element can be used at most once, so the next decision always considers the remaining elements.
