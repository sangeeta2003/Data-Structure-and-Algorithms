# 951. Flip Equivalent Binary Trees

## Problem

Two binary trees are **flip equivalent** if we can make them identical by swapping the left and right children of any nodes.

### Example

```text
Tree 1:       Tree 2:

    1             1
   / \           / \
  2   3         3   2
```

Flip the children of `1` → both trees become the same.

## Approach

For every pair of nodes:

1. Both are `NULL` → `true`
2. One is `NULL` → `false`
3. Values are different → `false`
4. Check **without flipping**
5. Check **with flipping**
6. If either case is true → trees are flip equivalent

### Key Idea

```text
Same root value
      ↓
 ┌────┴────┐
No Flip    Flip
   ↓          ↓
L ↔ L       L ↔ R
R ↔ R       R ↔ L
```

**Time:** `O(N)`
**Space:** `O(H)`

### Remember

> **At every node, try both: normal children matching OR swapped children matching.**
