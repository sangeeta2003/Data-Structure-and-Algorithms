# 🔢 Kth Smallest Number in Multiplication Table

## Approach

Use **Binary Search on Answer**.

We don't create the multiplication table. Instead, for every guessed value `mid`, count how many numbers in the table are `<= mid`.

For row `i`, the values are:

```text
i, 2i, 3i, 4i, ...
```

The number of values `<= mid` is:

```cpp
min(n, mid / i)
```

Add this for every row.

* If `count < k` → search in the right half.
* If `count >= k` → `mid` can be the answer, so search in the left half.

## Key Formula

```cpp
count += min(n, mid / i);
```

## Complexity

```text
Time:  O(m log(m × n))
Space: O(1)
```

## Key Pattern

```text
Binary Search on Answer
        ↓
Guess mid
        ↓
Count elements <= mid
        ↓
count < k  → increase low
count >= k → decrease high
```
