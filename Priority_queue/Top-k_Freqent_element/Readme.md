# LeetCode 347 - Top K Frequent Elements

## Problem

Given an integer array `nums`, return the `k` most frequent elements.

## Approach

* Use `unordered_map` to count the frequency of each element.
* Use a **min-heap (priority queue)** of size `k`.
* Keep the `k` elements with the highest frequencies.
* Extract the elements from the heap as the answer.

## Complexity

* **Time:** `O(n log k)`
* **Space:** `O(n)`

## Key Concept

**Hash Map + Min Heap**

The heap stores only `k` elements, so we don't need to sort the entire array.
