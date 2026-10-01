# 33. Search in Rotated Sorted Array

**Difficulty:** Medium
**Topic:** Binary Search

### Problem

Search for a `target` in a sorted array that has been rotated. Return its index, otherwise return `-1`.

**Example:**

```text
Input:  nums = [4,5,6,7,0,1,2], target = 0
Output: 4
```

### Approach

Use Binary Search.

* If `nums[mid] > nums[n-1]`, `mid` is in the **left part**.
* Otherwise, `mid` is in the **right part**.
* Check which side can contain the target and adjust `low` or `high`.

### Complexity

* **Time:** `O(log n)`
* **Space:** `O(1)`
