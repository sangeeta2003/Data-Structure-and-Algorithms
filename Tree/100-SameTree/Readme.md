# 100. Same Tree

## Problem

Given two binary trees `p` and `q`, check whether they are **exactly the same**.

Two trees are the same when:

1. Both nodes are `nullptr`, or
2. Both nodes exist and have the **same value**.
3. Their left subtrees are the same.
4. Their right subtrees are the same.

---

## Approach

Use **recursion**.

For every pair of nodes:

```text
1. Both null       → true
2. One null        → false
3. Different value → false
4. Check left subtree
5. Check right subtree
6. Both must be true
```

The recursive calls are:

```text
isSameTree(p->left, q->left)
isSameTree(p->right, q->right)
```

---

## Example

```text
Tree p:          Tree q:

    1                1
   / \              / \
  2   3            2   3
```

### Step 1 — Root

```text
p = 1
q = 1

1 == 1
```

So continue.

---

### Step 2 — Left subtree

```text
p = 2
q = 2

2 == 2
```

Continue.

Both left and right children are `nullptr`:

```text
p = nullptr
q = nullptr

→ true
```

Therefore node `2` is the same.

---

### Step 3 — Right subtree

```text
p = 3
q = 3

3 == 3
```

Again, their children are both `nullptr`.

```text
→ true
```

---

### Final Calculation

```text
r1 = left subtree result  = true
r2 = right subtree result = true

r1 && r2
= true && true
= true
```

Therefore:

```text
Output: true
```

---

## Example Where Trees Are Different

```text
p:              q:

    1               1
   /                 \
  2                   2
```

At root:

```text
1 == 1
```

So we continue.

Left side:

```text
p->left = 2
q->left = nullptr
```

One is `nullptr` and the other is not.

Therefore:

```text
→ false
```

The trees are not the same.

---

## Important Base Cases

These three checks are the most important:

```cpp
if(p == nullptr && q == nullptr)
    return true;
```

Both are empty → same.

```cpp
if(p == nullptr || q == nullptr)
    return false;
```

Only one is empty → different.

```cpp
if(p->val != q->val)
    return false;
```

Values are different → different.

---

## Recursion Pattern

Think of the problem as:

```text
Are these two nodes the same?
        ↓
Are their left children the same?
        ↓
Are their right children the same?
```

So:

```text
Same Tree
   |
   ├── Same Left Subtree
   |
   └── Same Right Subtree
```

Both subtrees must return `true`.

---

## Complexity

Let `N` be the number of nodes compared.

* **Time:** `O(N)`
* **Space:** `O(H)`

where `H` is the height of the tree because of the recursion stack.
