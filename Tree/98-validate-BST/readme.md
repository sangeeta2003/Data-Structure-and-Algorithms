# 98. Validate Binary Search Tree

## Approach

Use **Inorder Traversal**.

A Binary Search Tree always gives values in **strictly increasing order** during inorder traversal.

We keep track of the previous node using `prev`.

* If `prev == nullptr`, this is the first node.
* Otherwise, the current value must be **greater than** the previous value.
* If `root->val <= prev->val`, the tree is not a valid BST.

## Example

```text
       2
      / \
     1   3
```

Inorder traversal:

```text
1 → 2 → 3
```

Values are strictly increasing, so the answer is:

```text
true
```

### Invalid Example

```text
       5
      / \
     1   4
        / \
       3   6
```

Inorder:

```text
1 → 5 → 3 → 4 → 6
```

Here `3 < 5`, so the increasing order is broken.

Therefore:

```text
false
```

## Complexity

* **Time:** `O(n)`
* **Space:** `O(h)` for recursion stack, where `h` is tree height.
