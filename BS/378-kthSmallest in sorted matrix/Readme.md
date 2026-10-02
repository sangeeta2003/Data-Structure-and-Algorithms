# Kth Smallest Element in a Sorted Matrix

## Approach

Use **Binary Search on Answer + Staircase Search**.

* `low` = smallest element `matrix[0][0]`
* `high` = largest element `matrix[n-1][m-1]`
* For every `mid`, count how many elements are `<= mid`.
* Start from the **bottom-left** corner to count efficiently.
* If `count < k`, search for a larger value.
* Otherwise, store `mid` and search for a smaller value.

### Counting Elements

```cpp
if(matrix[row][col] <= guess) {
    cnt += row + 1;
    col++;
}
else {
    row--;
}
```

If `matrix[row][col] <= guess`, all elements above it in that column are also `<= guess`, so we add `row + 1`.

## Complexity

```text
Time:  O(n log(maxValue - minValue))
Space: O(1)
```

## Key Pattern

```text
Binary Search on Answer
        +
Count elements <= mid
        +
Staircase Search
```

The answer is the **smallest value for which at least `k` elements are smaller than or equal to it**.
