# 106. Construct Binary Tree from Inorder and Postorder

## Approach

Use **recursion + hashmap**.

* In `postorder`, the **last element is the root**.
* Find that root in `inorder`.
* Elements on the left are the left subtree.
* Elements on the right are the right subtree.
* Since we process `postorder` from right to left, build the **right subtree first**.

## Example

```text
inorder   = [9,3,15,20,7]
postorder = [9,15,7,20,3]
```

Last element of postorder is `3`.

```text
       3
      / \
     9   20
        /  \
       15   7
```

Processing order:

```text
3 → 20 → 7 → 15 → 9
```

## Key Code

```cpp
idx = postorder.size() - 1;

TreeNode* node = new TreeNode(postorder[idx--]);

int pos = mp[node->val];

node->right = fun(postorder, pos + 1, high);
node->left = fun(postorder, low, pos - 1);
```

## Complexity

* **Time:** `O(n)`
* **Space:** `O(n)`
