# 787. Cheapest Flights Within K Stops

## Approach: Bellman-Ford Algorithm

* Initialize the distance of the source city to `0` and all other cities to infinity.
* Run at most `k + 1` iterations because at most `k` stops allow `k + 1` flights.
* In each iteration, create a temporary copy of the distance array to ensure we use at most one additional flight per iteration.
* Relax every flight by updating the destination's cost if a cheaper route is found.
* Copy the temporary array back to the distance array after each iteration.
* Return `-1` if the destination is unreachable; otherwise, return its minimum cost.

## Complexity Analysis

* **Time Complexity:** `O((K + 1) * E)`, where `E` is the number of flights.
* **Space Complexity:** `O(V)`, where `V` is the number of cities.
