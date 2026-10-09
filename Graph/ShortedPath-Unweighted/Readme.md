# Shortest Path in Unweighted Graph

## Problem Statement

Given an undirected graph with `V` vertices and `E` edges, find the shortest distance between a source vertex `src` and a destination vertex `dest`. Each edge has a weight of `1`.

Return `-1` if no path exists between the source and destination.

## Approach: Breadth-First Search (BFS)

BFS finds the shortest path in an unweighted graph because it explores vertices level by level.

### Workflow

1. **Build the adjacency list:** Store each edge in both directions because the graph is undirected.
2. **Initialize distances:** Create a distance array of size `V`, filled with `-1`. Set `dist[src] = 0`.
3. **Initialize the queue:** Push the source vertex into the queue.
4. **Traverse using BFS:**

   * Remove the front vertex from the queue.
   * If it is the destination, return its distance.
   * For each unvisited neighbor, update its distance to `dist[node] + 1` and push it into the queue.
5. **Handle unreachable destinations:** If BFS finishes without reaching `dest`, return `-1`.

### Workflow Diagram

```text
          Start
            |
            v
    Build Adjacency List
            |
            v
    Initialize dist[src] = 0
       and enqueue src
            |
            v
       Queue Empty?
        /       \
      No         Yes
      |           |
      v           v
   Pop Node    Return -1
      |
      v
 Is node == dest?
    /       \
  Yes        No
   |          |
   v          v
Return     Explore Neighbors
Distance       |
               v
      Is Neighbor Unvisited?
               |
               v
   Update Distance and Enqueue
               |
               └── Repeat BFS
```

## Complexity Analysis

* **Time Complexity:** `O(V + E)` — each vertex and edge is processed at most a constant number of times.
* **Space Complexity:** `O(V + E)` — for the adjacency list, distance array, and BFS queue.

## Key Concepts

* Breadth-First Search (BFS)
* Graph representation using adjacency lists
* Shortest path in unweighted graphs
* Queue-based traversal
* Distance tracking and visited-state management

## Important Edge Cases

* `src == dest`: return `0`.
* Destination is unreachable: return `-1`.
* Graph has no edges.
* Source has no neighbors.
* Multiple paths exist: BFS finds the shortest one.

## Key Takeaway

**BFS is the optimal approach for finding the shortest path in an unweighted graph.** Assigning a distance when a vertex is first enqueued ensures that its shortest distance is recorded and prevents duplicate visits.
