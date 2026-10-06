# Zigzag Level Order Traversal

## Problem

Given the root of a binary tree, return its level order traversal in **zigzag order**.

* Level 1 → left to right
* Level 2 → right to left
* Level 3 → left to right
* Continue alternating.

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
[[3], [20, 9], [15, 7]]
```

---

## Approach

Use **BFS (Breadth-First Search)** with a queue.

For every level:

1. Store the number of nodes in `levelSize`.
2. Create a temporary array of that size.
3. Maintain two pointers:

   * `first = 0`
   * `last = levelSize - 1`
4. If direction is left → right, put the value at `first`.
5. If direction is right → left, put the value at `last`.
6. Move the corresponding pointer.
7. Add the children to the queue.
8. Change the direction for the next level.

---

## Pointer Calculation

Suppose the current level is:

```text
[9, 20, 30]
```

`levelSize = 3`

Initially:

```text
first = 0
last = 2
```

### Left → Right

```text
9  → temp[first] = temp[0]
      first++

20 → temp[1]
      first++

30 → temp[2]
      first++
```

Result:

```text
[9, 20, 30]
```

### Right → Left

Reset:

```text
first = 0
last = 2
```

```text
9  → temp[last] = temp[2]
      last--

20 → temp[1]
      last--

30 → temp[0]
      last--
```

Result:

```text
[30, 20, 9]
```

---

## Important Mistake

Do **not** put `first` and `last` inside the loop:

```cpp
while(levelSize--) {
    int first = 0;       // ❌ resets every time
    int last = levelSize - 1;
}
```

Instead:

```cpp
int first = 0;
int last = levelSize - 1;

while(levelSize--) {
    // use first and last
}
```

This allows the pointers to move across the entire level.

---

## Complexity

Let `N` be the number of nodes.

* **Time:** `O(N)`
* **Space:** `O(N)`

Every node is inserted into and removed from the queue exactly once.
