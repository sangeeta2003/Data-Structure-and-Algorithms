# LeetCode 124 - Binary Tree Maximum Path Sum

## Problem

Find the maximum path sum in a binary tree. The path can start and end at any nodes.

## Approach

* Use **DFS recursion**.
* For every node, calculate the maximum path sum that can be extended to its parent.
* A negative subtree is ignored using `max(0, ...)`.
* At each node, consider a path passing through both left and right children.
* Keep updating the global maximum.

## Example

**Input:**

```text
root = [-10,9,20,null,null,15,7]
```

**Output:**

```text
42
```

**Explanation:**

```text
15 → 20 → 7

15 + 20 + 7 = 42
```

## Complexity

* **Time:** O(N)
* **Space:** O(H)

Where `N` is the number of nodes and `H` is the height of the tree.
