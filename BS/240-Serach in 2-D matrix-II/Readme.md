# 🔍 Search a 2D Matrix II

## Approach

Start from the **bottom-left corner** of the matrix.

```text
row = n - 1
col = 0
```

At every position:

* If `matrix[row][col] == target` → return `true`
* If value `> target` → move **up**
* If value `< target` → move **right**

Why?

* Moving **up** gives smaller values.
* Moving **right** gives larger values.

Continue until we go outside the matrix.

## Complexity

```text
Time:  O(m + n)
Space: O(1)
```

## Difference from Search a 2D Matrix (LeetCode 74)

### Matrix I

The entire matrix behaves like **one sorted array**.

```text
1  3  5  7
10 11 16 20
23 30 34 60
```

We can use **Binary Search**.

```text
Time: O(log(m × n))
```

Convert the 1D index:

```cpp
row = mid / cols;
col = mid % cols;
```

### Matrix II

Here, each **row and each column** is sorted, but the entire matrix cannot necessarily be treated as one sorted array.

```text
1   4   7   11
2   5   8   12
3   6   9   16
10  13  14  17
```

So we use the **staircase search** from the bottom-left.

```text
Time: O(m + n)
```

### Key Difference

| Problem   | Search Method                  | Time            |
| --------- | ------------------------------ | --------------- |
| Matrix I  | Binary Search                  | `O(log(m × n))` |
| Matrix II | Bottom-left / Staircase Search | `O(m + n)`      |

**Remember:**

> Matrix I → treat it as a **1D sorted array**.
> Matrix II → use the **row + column sorted property**.
