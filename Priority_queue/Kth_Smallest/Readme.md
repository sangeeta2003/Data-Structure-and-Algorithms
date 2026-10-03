# Kth Smallest Element

### Approach

* Use a **max heap** of size `k`.
* Insert the first `k` elements into the heap.
* For every remaining element:

  * If it is greater than the heap's top, ignore it.
  * Otherwise, remove the largest element and insert the current element.
* The heap's top is the **kth smallest element**.

### Complexity

* **Time:** `O(n log k)`
* **Space:** `O(k)`

### Key Idea

The max heap keeps the **k smallest elements** seen so far, and its top always represents the largest among them — the current `kth` smallest.
