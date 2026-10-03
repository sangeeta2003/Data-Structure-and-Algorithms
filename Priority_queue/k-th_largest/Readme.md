# Kth Largest Element in an Array

### Approach

* Use a **min heap** of size `k`.
* Insert the first `k` elements.
* For each remaining element, if it is larger than the heap's top, remove the top and insert the current element.
* The heap's top is the **kth largest element**.

### Complexity

* **Time:** `O(n log k)`
* **Space:** `O(k)`

### Key Idea

The min heap maintains the **k largest elements**, and the smallest among them (`pq.top()`) is the kth largest overall.
