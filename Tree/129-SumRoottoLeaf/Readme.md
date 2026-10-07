# 129. Sum Root to Leaf Numbers

## Approach

Use **recursion** to build the number represented by each root-to-leaf path.

* At each node, update the current number as `sum = sum * 10 + root->val`.
* When a leaf node is reached, add the formed number to `res`.
* Continue recursively for both left and right subtrees.
* Finally, return the total sum.

## Example

```text
Input:
root = [1,2,3]

Tree:
    1
   / \
  2   3

Paths:
1 → 2 = 12
1 → 3 = 13

Output:
12 + 13 = 25
```

## Complexity

* **Time:** O(n)
* **Space:** O(h), where `h` is the tree height.
