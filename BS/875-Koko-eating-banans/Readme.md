# 875. Koko Eating Bananas

**Difficulty:** Medium
**Topic:** Binary Search on Answer

### Problem

Find the minimum eating speed `k` such that Koko can finish all banana piles within `h` hours.

**Example:**

```text
Input:  piles = [3,6,7,11], h = 8
Output: 4
```

### Approach

Use Binary Search on the possible eating speed.

* `low = 1`
* `high = max(piles)`
* Calculate the total hours required for `mid` speed.
* If `hours > h` → speed is too slow → `low = mid + 1`
* Otherwise → speed works → save answer and search for a smaller speed.

Use `long long` for the total hours to avoid integer overflow.

### Complexity

* **Time:** `O(n log(max(piles)))`
* **Space:** `O(1)`
