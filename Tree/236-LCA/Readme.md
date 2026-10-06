# 236. Lowest Common Ancestor of a Binary Tree

## Problem

Given a binary tree and two nodes `p` and `q`, find their **Lowest Common Ancestor (LCA)**.

The LCA is the lowest node in the tree that has both `p` and `q` in its subtree.

## Approach

Use **recursion + counting**.

For every node:

* `left` → how many of `p` and `q` are found in the left subtree.
* `right` → how many are found in the right subtree.
* `self` → `1` if the current node is `p` or `q`.
* `total = left + right + self`

When:

```text
total == 2
```

the current node contains both `p` and `q`, so it is the LCA.

We store the **first/lowest node** where `total == 2`.

## Example

```text
        3
       / \
      5   1
     / \
    6   2
```

For `p = 6` and `q = 2`:

```text
At node 5:

left  = 1  → found 6
right = 1  → found 2
self  = 0

total = 1 + 1 + 0 = 2
```

Therefore, `5` is the LCA.

## Key Idea

```text
left + right + self = 2
              ↓
         LCA found
```

## Complexity

**Time:** `O(N)`

**Space:** `O(H)` due to recursion, where `H` is the tree height.
