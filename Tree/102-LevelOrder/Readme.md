# 102. Binary Tree Level Order Traversal

## Problem

Given a binary tree, return its nodes **level by level**, from **left to right**.

### Example

```text
        3
       / \
      9   20
         /  \
        15   7
```

Output:

```text
[[3], [9,20], [15,7]]
```

## Approach — BFS

Use a **Queue** because we need to process nodes level by level.

### How it works

1. Put the root into the queue.
2. Find the number of nodes currently in the queue → this is the current level size.
3. Remove exactly those nodes from the queue.
4. Store their values in a temporary vector.
5. Add their left and right children to the queue.
6. Add the temporary vector to the result.
7. Repeat until the queue is empty.

### Example Calculation

Initially:

```text
Queue = [3]
Result = []
```

**Level 1:**

```text
levelSize = 1

Take 3
temp = [3]

Add children: 9, 20

Queue = [9, 20]
Result = [[3]]
```

**Level 2:**

```text
levelSize = 2

Take 9 → temp = [9]
Take 20 → temp = [9, 20]

Add children of 20: 15, 7

Queue = [15, 7]
Result = [[3], [9,20]]
```

**Level 3:**

```text
levelSize = 2

Take 15 → temp = [15]
Take 7  → temp = [15,7]

Queue = []
Result = [[3], [9,20], [15,7]]
```

Queue is empty, so we stop.

## Important Point

```text
levelSize = q.size()
```

is important because it tells us **how many nodes belong to the current level**.

Also:

```text
vector<int> temp;
```

should be empty because we add values using `push_back()`.

## Complexity

* **Time:** O(N)
* **Space:** O(N)

Where `N` is the number of nodes in the tree.

## Pattern to Remember

**Tree → Level by Level → BFS → Queue**

```text
Queue
  ↓
Process current level
  ↓
Add children
  ↓
Next level
```
