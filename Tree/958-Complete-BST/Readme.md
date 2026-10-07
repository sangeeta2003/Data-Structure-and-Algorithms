# LeetCode 958 - Check Completeness of a Binary Tree

## Approach

Use **BFS (Level Order Traversal)** with a queue.

* Traverse the tree level by level.
* Once a `NULL` node is found, set a flag `isNull = true`.
* After a `NULL` is found, if any non-null node appears, the tree is **not complete**.
* Otherwise, the tree is complete.

## Example

```text
        1
       / \
      2   3
     / \
    4   5
```

Level order:

```text
1 → 2 → 3 → 4 → 5 → NULL → NULL
```

After the first `NULL`, there are no more actual nodes, so the tree is complete.

**Output:**

```text
true
```

## Complexity

* **Time:** O(N)
* **Space:** O(N)
