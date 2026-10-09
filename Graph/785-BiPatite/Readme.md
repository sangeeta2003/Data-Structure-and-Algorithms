# Is Graph Bipartite?

**Problem:** Determine whether an undirected graph is bipartite. A graph is bipartite if its vertices can be divided into two groups such that no two adjacent vertices belong to the same group.

### Approach: DFS + Graph Coloring

* Initialize all vertices with color `-1` (unvisited).
* Assign color `0` to the starting vertex.
* Use DFS to color each adjacent vertex with the opposite color (`1 - c`).
* If two adjacent vertices have the same color, the graph is not bipartite.
* Check every connected component of the graph.

### Complexity

* **Time:** `O(V + E)`
* **Space:** `O(V)` for the color array and DFS recursion stack.

### Key Concepts

* Depth-First Search (DFS)
* Graph Coloring
* Connected Components
