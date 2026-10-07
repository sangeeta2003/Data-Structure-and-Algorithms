# 105. Construct Binary Tree from Preorder and Inorder Traversal

## Approach

Use **Preorder + Inorder** with recursion.

* **Preorder:** first element is always the root.
* **Inorder:** elements before the root belong to the left subtree, and elements after it belong to the right subtree.
* Use a hashmap to quickly find the root's index in inorder.

## Example

```text
Preorder = [3,9,20,15,7]
Inorder  = [9,3,15,20,7]
```

First:

```text
Preorder → 3 is root
Inorder  → [9] 3 [15,20,7]
             L    R
```

So:

```text
       3
      / \
     9   20
        /  \
       15   7
```

Next preorder element is `9`, so it becomes the left child.

Then `20` becomes the right child, and its inorder split creates `15` and `7`.

## Key Code

```cpp
TreeNode* node = new TreeNode(preorder[idx]);
idx++;

int id = in[node->val];

node->left = fun(preorder, low, id - 1);
node->right = fun(preorder, id + 1, high);
```

`idx` moves through preorder, while `id` divides the inorder array.

## Complexity

* **Time:** `O(n)`
* **Space:** `O(n)` for the hashmap and recursion.
