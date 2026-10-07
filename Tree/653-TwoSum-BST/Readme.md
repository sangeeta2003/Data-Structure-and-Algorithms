# 653. Two Sum IV - Input is a BST

**Difficulty:** Easy
**Language:** C++

## Problem

Given a Binary Search Tree and an integer `k`, check whether two different nodes exist whose values add up to `k`.

## Approach

1. Perform **inorder traversal** of the BST.
2. Inorder traversal gives the values in **sorted order**.
3. Use the **two-pointer approach**:

   * `i` starts from the beginning.
   * `j` starts from the end.
4. If the sum is equal to `k`, return `true`.
5. If the sum is smaller, move `i` forward.
6. Otherwise, move `j` backward.

## Example

### Input

```text
root = [5,3,6,2,4,null,7]
k = 9
```

Inorder traversal:

```text
[2, 3, 4, 5, 6, 7]
```

Two values:

```text
2 + 7 = 9
```

### Output

```text
true
```

## Complexity

* **Time:** O(n)
* **Space:** O(n)

## Key Idea

**BST → Inorder → Sorted Array → Two Pointers**
