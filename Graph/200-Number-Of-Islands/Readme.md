# Number of Islands

**Problem:** Given an `m × n` grid of `'1'` (land) and `'0'` (water), count the number of islands. Islands are connected horizontally or vertically.

### Approach: DFS

* Traverse every cell in the grid.
* If a cell contains land (`'1'`) and is not visited, increment the island count.
* Use DFS to visit all connected land cells in the four directions: up, down, left, and right.
* Continue until every cell has been checked.

### Complexity

* **Time:** `O(m × n)`
* **Space:** `O(m × n)` for the visited matrix and worst-case DFS recursion stack.

### Key Concepts

* Depth-First Search (DFS)
* Graph Traversal
* 2D Visited Matrix
