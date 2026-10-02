#  Aggressive Cows

## Problem

Given stall positions and `k` cows, place the cows so that the **minimum distance between any two cows is maximized**.

### Example

```text
Input:
arr = [1, 2, 4, 8, 9]
k = 3

Output:
3
```

## Approach

Use **Binary Search on Answer + Greedy**.

1. Sort the stall positions.
2. Binary search the possible minimum distance.
3. Use a greedy function to check if `k` cows can be placed with at least `mid` distance.
4. If possible, increase the distance.
5. Otherwise, decrease the distance.

## Complexity

```text
Sorting: O(n log n)

Binary Search + Greedy:
O(n log(max(arr) - min(arr)))

Space: O(1)
```

## Key Pattern

```text
Binary Search on Answer
        +
Greedy Feasibility Check
```
