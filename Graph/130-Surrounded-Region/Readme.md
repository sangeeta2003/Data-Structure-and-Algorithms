# Surrounded Regions

## Problem Statement

Given an `m x n` board containing `'X'` and `'O'`, capture all regions of `'O'` that are completely surrounded by `'X'`.

An `'O'` connected to a board boundary must not be captured. Connectivity is horizontal or vertical.

## Approach: Boundary-Based DFS

Instead of searching for surrounded regions directly, identify the `'O'` cells that **cannot be captured**.

1. Traverse the first and last rows and columns.
2. Run DFS from every boundary cell containing `'O'`.
3. Mark every connected `'O'` as `'#'` to protect it.
4. Traverse the entire board:

   * Convert remaining `'O'` cells to `'X'`.
   * Restore `'#'` cells to `'O'`.

## Project Workflow

```text
        Start
          |
          v
    Read the board
          |
          v
   Check boundary cells
          |
          v
   Is the cell 'O'?
      /         \
    Yes          No
     |            |
     v            v
   Run DFS      Skip cell
     |
     v
 Mark connected
 'O' cells as '#'
     |
     v
 Traverse the board
     |
     v
 Is the cell '#'? ---- Yes ---> Restore to 'O'
     |
     No
     |
     v
 Is the cell 'O'? ---- Yes ---> Convert to 'X'
     |
     v
 Return modified board
```

## Complexity Analysis

* **Time Complexity:** `O(m × n)` — each cell is processed a constant number of times.
* **Auxiliary Space:** `O(m × n)` in the worst case due to the recursive DFS call stack.

## Key Concepts

* Depth-First Search (DFS)
* Graph traversal
* Boundary-based traversal
* In-place matrix modification
* Four-directional movement

## Important Edge Cases

* Empty board
* Single-row or single-column board
* All cells are `'X'`
* Boundary-connected `'O'` cells
* Completely surrounded `'O'` regions

## Conclusion

The key insight is to **preserve boundary-connected regions first**. Every remaining `'O'` is surrounded and should be converted to `'X'`.
