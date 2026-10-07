# 99. Recover Binary Search Tree

## Approach

Use **inorder traversal** because a valid BST has values in increasing order.

While traversing, compare the current node with the previous node.

* If `root->val < prev->val`, we found a wrong order.
* For the **first violation**, store `prev` and `root`.
* For the **second violation**, update the second wrong node.
* Finally, swap the values of the two incorrect nodes.

### Example

```text
       3
      / \
     1   4
        /
       2
```

Inorder:

```text
1 → 3 → 2 → 4
```

Violation:

```text
3 > 2
```

Swap `3` and `2`:

```text
1 → 2 → 3 → 4
```

The BST is recovered.

## Complexity

* **Time:** `O(n)`
* **Space:** `O(h)` for recursion stack.
