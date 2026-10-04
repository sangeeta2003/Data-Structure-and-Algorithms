# Merge K Sorted Arrays

### Approach

* Use a **min-heap (priority queue)** to store the smallest element from each row.
* Each heap node stores:

  * `value`
  * `row`
  * `column`
* Remove the smallest element, add it to the result, then push the next element from the same row.
* Continue until the heap is empty.

### Complexity

* **Time:** `O(n × m × log n)`
* **Space:** `O(n)`
