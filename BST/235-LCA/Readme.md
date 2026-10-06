# 235. Lowest Common Ancestor of a Binary Search Tree

## Problem

Given a **Binary Search Tree (BST)** and two nodes `p` and `q`, find their **Lowest Common Ancestor (LCA)**.

The LCA is the lowest node that contains both `p` and `q` in its subtree.

## Approach

Use the **BST property**:

* If both `p` and `q` are greater than the current node → go **right**.
* If both `p` and `q` are smaller than the current node → go **left**.
* Otherwise, the current node is the **LCA**.
* If the current node is `p` or `q`, it can also be the LCA.

## Example

```text
        6
       / \
      2   8
     / \ / \
    0  4 7  9
      / \
     3   5
```

For `p = 2` and `q = 8`:

```text
2 < 6 < 8
```

So `6` lies between `p` and `q`.

Therefore:

```text
LCA = 6
```

## Complexity

**Time:** `O(H)`

**Space:** `O(H)` due to recursion, where `H` is the height of the BST.
