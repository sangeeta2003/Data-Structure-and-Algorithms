# 107. Binary Tree Level Order Traversal II

## Problem

Given the root of a binary tree, return its **level order traversal from bottom to top**.

Normal level order:

```text
Root → Level 2 → Level 3
```

But here we need:

```text
Bottom Level → Level 2 → Root
```

### Example

```text
        3
       / \
      9   20
         /  \
        15   7
```

Normal level order:

```text
[[3], [9,20], [15,7]]
```

Required answer:

```text
[[15,7], [9,20], [3]]
```

---

## Approach

Use **BFS (Level Order Traversal)** with a queue.

### Steps

1. If `root == nullptr`, return an empty result.
2. Put the root into the queue.
3. Process one complete level at a time.
4. Store every level in `res`.
5. After BFS is finished, reverse `res`.
6. Return the reversed result.

---

## Calculation

For this tree:

```text
        3
       / \
      9   20
         /  \
        15   7
```

### Level 1

Queue:

```text
[3]
```

Process `3`:

```text
temp = [3]
```

Add its children:

```text
Queue = [9, 20]
```

Result:

```text
res = [[3]]
```

---

### Level 2

Queue:

```text
[9, 20]
```

Process `9` and `20`:

```text
temp = [9, 20]
```

Add children of `20`:

```text
Queue = [15, 7]
```

Result:

```text
res = [[3], [9,20]]
```

---

### Level 3

Queue:

```text
[15, 7]
```

Process them:

```text
temp = [15, 7]
```

Result:

```text
res = [[3], [9,20], [15,7]]
```

---

### Finally Reverse

Before:

```text
[[3], [9,20], [15,7]]
```

After:

```text
[[15,7], [9,20], [3]]
```

This is the required answer.

---

## Key Idea

This problem is almost the same as **normal Level Order Traversal**.

The only extra step is:

```text
BFS → store levels → reverse result
```

---

## Complexity

Let `N` be the number of nodes.

* **Time:** `O(N)`
* **Space:** `O(N)`

Every node is visited exactly once.
