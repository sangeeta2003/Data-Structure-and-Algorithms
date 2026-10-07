# 112. Path Sum

## Approach

Use **recursion** to explore every root-to-leaf path.

* Keep a running `sum` of the values along the current path.
* When a leaf node is reached, check whether the sum equals `targetSum`.
* If any path matches, the result is `true`.
* Otherwise, return `false`.

## Example

```text
Input:
root = [5,4,8,11,null,13,4,7,2,null,null,null,1]
targetSum = 22

Output:
true
```

The path `5 → 4 → 11 → 2` has sum `22`.

## Complexity

* **Time:** O(n)
* **Space:** O(h), where `h` is the height of the tree.
