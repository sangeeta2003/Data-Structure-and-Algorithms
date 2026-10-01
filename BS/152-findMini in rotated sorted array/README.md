# 153. Find Minimum in Rotated Sorted Array

**Difficulty:** Medium
**Topic:** Binary Search

### Problem

Find the minimum element in a sorted array that has been rotated.

**Example:**

```text
Input:  [3,4,5,1,2]
Output: 1
```

### Approach

Compare `nums[mid]` with the last element:

* `nums[mid] > nums[n-1]` → minimum is on the **right**.
* Otherwise → `mid` can be the answer, search on the **left**.

### Complexity

* **Time:** `O(log n)`
* **Space:** `O(1)`
