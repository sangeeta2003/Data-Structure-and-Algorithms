# 230. Kth Smallest Element in a BST

**Difficulty:** Medium
**Language:** C++

## Problem

Given a Binary Search Tree and an integer `k`, return the **kth smallest value** in the tree.

## Approach

1. Perform an **inorder traversal** of the BST.
2. Inorder traversal gives the values in **sorted order**.
3. The kth smallest element is at index `k - 1`.

## Example

### Input

```text
root = [3,1,4,null,2]
k = 1
```

Inorder traversal:

```text
[1, 2, 3, 4]
```

The 1st smallest value is:

```text
1
```

### Output

```text
1
```

## Complexity

* **Time:** O(n)
* **Space:** O(n)

## Key Idea

**BST → Inorder Traversal → Sorted Order → `k - 1` index**
