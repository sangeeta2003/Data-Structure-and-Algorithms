# Rotting Oranges

**Problem:** Given a grid where `0` represents an empty cell, `1` represents a fresh orange, and `2` represents a rotten orange, find the minimum time required for all fresh oranges to rot. Each minute, rotten oranges infect adjacent fresh oranges in four directions.

### Approach: Multi-Source BFS

* Add all initially rotten oranges to a queue.
* Count the total number of fresh oranges.
* Process the queue level by level, representing each minute.
* Mark newly rotten oranges as visited and decrease the fresh orange count.
* Return `-1` if any fresh oranges remain; otherwise, return the total time.

### Complexity

* **Time:** `O(n × m)`
* **Space:** `O(n × m)`

### Key Concepts

* Breadth-First Search (BFS)
* Multi-Source BFS
* Queue
* Level-by-Level Traversal
