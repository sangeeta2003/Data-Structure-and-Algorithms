# Minimum Spanning Tree (GFG)

## Approach: Prim's Algorithm

* Build an adjacency list to represent the undirected weighted graph.
* Use a min-heap to always select the edge with the minimum weight.
* Start from vertex `0` with an initial weight of `0`.
* Extract the minimum-weight edge from the priority queue.
* If the vertex is already visited, skip it; otherwise, mark it visited and add its edge weight to the MST sum.
* Push all edges leading to unvisited neighboring vertices into the priority queue.
* Continue until the priority queue becomes empty and return the total MST weight.

## Complexity Analysis

* **Time Complexity:** `O(E log E)`, where `E` is the number of edges.
* **Space Complexity:** `O(V + E)`, where `V` is the number of vertices.
