#  Search a 2D Matrix

## Approach

Treat the 2D matrix as a **sorted 1D array** and apply Binary Search.

* Set `low = 0` and `high = rows * cols - 1`.
* Calculate `mid`.
* Convert the 1D index to matrix coordinates:

  ```cpp
  row = mid / cols;
  col = mid % cols;
  ```
* Compare `matrix[row][col]` with `target`.
* If equal, return `true`.
* If smaller, search the right half.
* If greater, search the left half.
* If the target is not found, return `false`.

### Complexity

```text
Time:  O(log(m × n))
Space: O(1)
```
