# LeetCode 113 - Path Sum II

## Problem

Given the root of a binary tree and a target sum, return all root-to-leaf paths where the sum of node values equals the target sum.

## Approach

* Use **DFS recursion** to traverse the tree.
* Keep track of the current path using a vector.
* Keep adding node values to the current sum.
* When reaching a leaf, check if the sum equals `targetSum`.
* If it matches, store the current path in the result.
* Use **backtracking** by removing the last node before returning.

## Example

**Input:**

```text
root = [5,4,8,11,null,13,4,7,2,null,null,5,1]
targetSum = 22
```

**Output:**

```text
[[5,4,11,2],
 [5,8,4,5]]
```

## Complexity

* **Time:** O(N)
* **Space:** O(H) for recursion and the current path

Where `N` is the number of nodes and `H` is the height of the tree.
