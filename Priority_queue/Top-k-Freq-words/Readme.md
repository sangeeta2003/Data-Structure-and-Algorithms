# LeetCode 692 - Top K Frequent Words

## Problem

Given an array of strings `words`, return the `k` most frequent words.

The result should be sorted by:

1. **Frequency** — highest to lowest
2. **Lexicographical order** — for equal frequencies

## Approach

* Use `unordered_map` to count word frequencies.
* Use a **min-heap** of size `k`.
* Keep the `k` most frequent words in the heap.
* Reverse the extracted result to get the required order.

## Complexity

* **Time:** `O(n log k)`
* **Space:** `O(n)`

## Key Concept

**Hash Map + Custom Comparator + Min Heap**
