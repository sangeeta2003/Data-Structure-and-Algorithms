# 226. Invert Binary Tree

## 🧩 Problem

Given the root of a binary tree, **invert the tree** and return its root.

Inverting a binary tree means:

> At every node, swap its **left child** and **right child**.

### Example

Original tree:

```text
        4
       / \
      2   7
     / \ / \
    1  3 6  9
```

After inversion:

```text
        4
       / \
      7   2
     / \ / \
    9  6 3  1
```

So:

```text
Input:
[4,2,7,1,3,6,9]

Output:
[4,7,2,9,6,3,1]
```

---

# 💡 Main Idea

For every node:

```text
1. Swap left and right.
2. Invert the left subtree.
3. Invert the right subtree.
```

This is a natural **recursion** problem because every subtree is itself a smaller binary tree.

---

# 🔁 Recursive Thinking

Suppose we have:

```text
        4
       / \
      2   7
```

At node `4`:

```text
left  = 2
right = 7
```

Swap them:

```text
        4
       / \
      7   2
```

Now we still need to invert the subtrees of `7` and `2`.

So:

```text
fun(root->left);
fun(root->right);
```

---

# 🛑 Base Case

If the current node is `NULL`:

```text
      NULL
```

There is nothing to invert.

So simply return.

```text
if(root == nullptr)
    return;
```

---

# 🧮 Dry Run

Consider:

```text
        4
       / \
      2   7
     / \ / \
    1  3 6  9
```

## Step 1 — Start at 4

Current node:

```text
4
```

Children:

```text
left = 2
right = 7
```

Swap:

```text
        4
       / \
      7   2
```

Then recursively process `7` and `2`.

---

## Step 2 — Process 7

Before:

```text
      7
     / \
    6   9
```

Swap:

```text
      7
     / \
    9   6
```

Then process `9` and `6`.

Both are leaf nodes.

For `9`:

```text
left = NULL
right = NULL
```

Nothing to swap further.

Same for `6`.

---

## Step 3 — Process 2

Before:

```text
      2
     / \
    1   3
```

Swap:

```text
      2
     / \
    3   1
```

Again, `3` and `1` are leaf nodes.

---

# ✅ Final Tree

After every node has been processed:

```text
        4
       / \
      7   2
     / \ / \
    9  6 3  1
```

Therefore:

```text
[4,7,2,9,6,3,1]
```

---

# 🧠 Why Recursion Works

A binary tree contains smaller binary trees.

For example:

```text
        4
       / \
      2   7
     / \ / \
    1  3 6  9
```

The tree can be viewed as:

```text
          4
        /   \
      Tree   Tree
       2      7
```

If we know how to invert **one tree**, we can use the same logic for its left and right subtrees.

That's exactly what recursion does.

---

# ⚠️ Important Detail About `void`

A common mistake is:

```text
void fun(TreeNode* root)
```

and then:

```text
return fun(root);
```

This is wrong because `fun()` returns `void`.

Instead:

```text
fun(root);
return root;
```

The helper modifies the existing tree, so after the helper finishes, the original `root` already points to the inverted tree.

---

# 🔑 Pattern to Remember

The complete recursive pattern is:

```text
fun(root)

    if root is NULL
        return

    swap(root->left, root->right)

    fun(root->left)

    fun(root->right)
```

Then:

```text
invertTree(root)

    fun(root)

    return root
```

---

# ⏱️ Complexity

Let `N` = number of nodes.

### Time Complexity

```text
O(N)
```

Every node is visited once.

### Space Complexity

```text
O(H)
```

where `H` is the height of the tree because of the recursive call stack.

For a balanced tree:

```text
O(log N)
```

For a skewed tree:

```text
O(N)
```

---

# 📝 Quick Revision

When you see **Invert Binary Tree**, immediately think:

```text
Swap left and right
        ↓
Recursively invert left
        ↓
Recursively invert right
```

The key line is:

```text
swap(root->left, root->right)
```

### One-line memory trick

> **At every node, swap the children and do the same thing for both subtrees.**
