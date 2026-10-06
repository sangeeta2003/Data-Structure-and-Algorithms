# 700. Search in a Binary Search Tree

## Problem

Given a **Binary Search Tree (BST)** and a value `val`, find the node whose value is equal to `val`.

If found, return the **subtree rooted at that node**. Otherwise, return `null`.

## Approach

Use the property of a BST:

* If `root->val == val` → node found.
* If `val < root->val` → search in the **left subtree**.
* If `val > root->val` → search in the **right subtree**.
* If `root == nullptr` → value doesn't exist.

## Example

```text
        4
       / \
      2   7
     / \
    1   3
```

For `val = 2`:

```text
4 > 2 → go left
2 == 2 → found
```

Return the subtree:

```text
      2
     / \
    1   3
```

## Complexity

**Time:** `O(H)`

**Space:** `O(H)` due to recursion, where `H` is the height of the BST.
