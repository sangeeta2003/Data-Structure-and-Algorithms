# 778. Swim in Rising Water

## Approach: Binary Search + DFS

* Find the minimum and maximum elevations in the grid to set the binary search range.
* Use binary search to guess the minimum time required to reach the bottom-right cell.
* For each guessed time, use DFS to check whether a valid path exists from the top-left to the bottom-right cell.
* DFS visits only cells whose elevation is less than or equal to the guessed time, while avoiding out-of-bounds cells and already visited cells.
* If the destination is reachable, store the answer and search for a smaller time. Otherwise, increase the time.
* Return the minimum feasible time.

## Complexity Analysis

* **Time Complexity:** `O(N² log H)` where `N` is the grid dimension and `H` is the elevation range.
* **Space Complexity:** `O(N²)` for the visited matrix and DFS recursion stack.
