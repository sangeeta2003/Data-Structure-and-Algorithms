# 743. Network Delay Time

## Approach: Dijkstra's Algorithm

* Build an adjacency list to represent the directed weighted graph.
* Use a min-heap to process the node with the smallest distance.
* Update shortest distances whenever a shorter path is found.
* If any node is unreachable, return `-1`; otherwise, return the maximum distance.

## Complexity

* **Time:** \(O((V+E)\log V)\)
* **Space:** \(O(V+E)\)
