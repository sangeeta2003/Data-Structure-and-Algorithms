# 743. Network Delay Time

## Approach: Dijkstra's Algorithm

* Build an adjacency list for the directed weighted graph.
* Use a min-heap to process the node with the smallest distance.
* Relax edges and update shortest distances.
* If any node is unreachable, return `-1`; otherwise, return the maximum distance.

## Complexity

* **Time:** \(O((V+E)\log V)\)
* **Space:** \(O(V+E)\)
