# 543. Diameter of Binary Tree

## Approach

Use **DFS (recursion)** to calculate the height of each node.

* `left` = height of left subtree
* `right` = height of right subtree
* Diameter through current node = `left + right`
* Return height = `1 + max(left, right)`

## Example

```text
       1
      / \
     2   3
    / \
   4   5
```

At node `2`:

* left = 1
* right = 1
* diameter = `1 + 1 = 2`

At node `1`:

* left = 2
* right = 1
* diameter = `2 + 1 = 3`

Answer = **3**

## Complexity

* Time: `O(n)`
* Space: `O(h)` — recursion stack
