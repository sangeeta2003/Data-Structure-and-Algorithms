# 101. Symmetric Tree

## 🧩 Problem

Given the root of a binary tree, check whether the tree is **symmetric around its center**.

A tree is symmetric when its left and right sides are **mirror images** of each other.

### Example

```text
        1
       / \
      2   2
     / \ / \
    3  4 4  3
```

This tree is symmetric because:

```text
left side       right side
---------       ----------
    2     ↔         2
   / \             / \
  3   4           4   3
```

Notice that we don't compare:

```text
left.left  with right.left
```

Instead, because it is a **mirror**, we compare:

```text
left.left  ↔ right.right
left.right ↔ right.left
```

---

## 💡 Main Idea

The root itself does not need to be compared with anything.

We need to check whether:

```text
root->left
```

and

```text
root->right
```

are mirror images.

Create a recursive function:

```text
fun(node1, node2)
```

It checks whether `node1` and `node2` are mirror images.

---

## 🔍 Recursive Cases

There are only a few important cases.

### Case 1: Both nodes are NULL

```text
node1 = NULL
node2 = NULL
```

There is nothing left to compare.

So they are symmetric.

```text
return true
```

---

### Case 2: One node is NULL

```text
node1 = NULL
node2 = 5
```

or

```text
node1 = 5
node2 = NULL
```

The structure is different.

So:

```text
return false
```

---

### Case 3: Values are different

Suppose:

```text
node1 = 2
node2 = 5
```

Their values are different, so they cannot be mirror images.

```text
return false
```

---

### Case 4: Values are equal

Suppose:

```text
node1 = 2
node2 = 2
```

The current nodes match.

Now we need to check their children **in mirror order**.

```text
node1->left  ↔ node2->right

node1->right ↔ node2->left
```

So recursively:

```text
r1 = fun(node1->left, node2->right)

r2 = fun(node1->right, node2->left)
```

Both must be true.

```text
return r1 && r2
```

---

# 🧮 Dry Run

Consider:

```text
        1
       / \
      2   2
     / \ / \
    3  4 4  3
```

We initially call:

```text
fun(root->left, root->right)
```

So:

```text
fun(2, 2)
```

### Step 1

```text
2 == 2
```

Good.

Now compare:

```text
left.left  ↔ right.right

3 ↔ 3
```

So:

```text
fun(3, 3)
```

Values match.

Both children are NULL:

```text
fun(NULL, NULL)
```

Returns:

```text
true
```

---

### Step 2

Now compare:

```text
left.right ↔ right.left

4 ↔ 4
```

So:

```text
fun(4, 4)
```

Again both values match and their children are NULL.

Returns:

```text
true
```

---

### Step 3

For the two `2` nodes:

```text
r1 = true
r2 = true
```

Therefore:

```text
r1 && r2
= true && true
= true
```

So the entire tree is symmetric.

---

# ❌ Example Where It Fails

Consider:

```text
        1
       / \
      2   2
       \   \
        3   3
```

We compare:

```text
left = 2
right = 2
```

Values match.

Now mirror comparison:

```text
left.left  ↔ right.right

NULL ↔ 3
```

One is NULL and the other isn't.

Therefore:

```text
false
```

So the tree is **not symmetric**.

---

# 🧠 The Most Important Thing to Remember

For **Symmetric Tree**, remember this pattern:

```text
           node1        node2
           /  \         /  \
          L    R       L    R
```

Mirror comparison is:

```text
node1->left  ↔ node2->right

node1->right ↔ node2->left
```

### ⭐ Shortcut to remember

> **Left with Right, Right with Left**

This is the key idea of the entire problem.

---

# 🔁 Recursive Structure

The recursion follows this pattern:

```text
fun(node1, node2)

    if both NULL
        true

    if one NULL
        false

    if values different
        false

    check:
        left of node1  with right of node2
        right of node1 with left of node2

    both must be true
```

---

# ⏱️ Complexity

Let `N` be the number of nodes.

### Time Complexity

```text
O(N)
```

Each node is visited at most once during the mirror comparison.

### Space Complexity

```text
O(H)
```

where `H` is the height of the tree, because of the recursive call stack.

For a balanced tree:

```text
O(log N)
```

For a completely skewed tree:

```text
O(N)
```

---

# 📌 Pattern Learned

This problem teaches an important **Binary Tree + Recursion** pattern:

```text
Compare two subtrees recursively
```

Instead of writing:

```text
fun(root)
```

we write:

```text
fun(node1, node2)
```

because we need to compare **two nodes at the same time**.

This pattern is useful in problems involving:

* Mirror trees
* Same Tree
* Symmetric Tree
* Comparing two binary trees
* Checking corresponding subtrees

---

# 📝 Quick Revision

Before solving this problem again, remember only these 4 things:

```text
1. Compare root->left and root->right.

2. Both NULL → true.

3. One NULL or values different → false.

4. Mirror:
       left-left  ↔ right-right
       left-right ↔ right-left
```

### Final Formula

```text
fun(left1, right2) &&
fun(right1, left2)
```

The entire problem is basically:

> **Are the left and right subtrees mirror images of each other?**
