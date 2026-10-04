# 23. Merge K Sorted Lists

## Problem

You are given `k` sorted linked lists.

Merge all of them into **one sorted linked list**.

### Example

```text
List 1: 1 → 4 → 5
List 2: 1 → 3 → 4
List 3: 2 → 6
```

We need:

```text
1 → 1 → 2 → 3 → 4 → 4 → 5 → 6
```

---

## Idea

This is a **K-Way Merge** problem.

Since every list is already sorted, we don't need to put all nodes into an array and sort them.

Use a **Min Heap**.

The heap always tells us the **smallest current node** among all lists.

---

## Step-by-Step Calculation

Initially take the first node from every list:

```text
List 1 → 1
List 2 → 1
List 3 → 2
```

Min Heap:

```text
1, 1, 2
```

### Step 1

Take smallest `1` from List 1.

```text
Answer: 1
```

Now List 1's next node is `4`.

Push `4`.

```text
Heap: 1, 2, 4
```

---

### Step 2

Take `1` from List 2.

```text
Answer: 1 → 1
```

Next node from List 2 is `3`.

```text
Heap: 2, 3, 4
```

---

### Step 3

Take `2` from List 3.

```text
Answer: 1 → 1 → 2
```

Next node is `6`.

```text
Heap: 3, 4, 6
```

---

### Step 4

Take `3`.

```text
Answer: 1 → 1 → 2 → 3
```

Next node from List 2 is `4`.

```text
Heap: 4, 4, 6
```

---

Continue the same process:

```text
Heap → 4, 4, 6
Take 4
Heap → 4, 5, 6
Take 4
Heap → 5, 6
Take 5
Heap → 6
Take 6
Heap → empty
```

Final answer:

```text
1 → 1 → 2 → 3 → 4 → 4 → 5 → 6
```

---

## What is stored in the Heap?

We store **ListNode pointers**, not values.

```cpp
priority_queue<ListNode*,
               vector<ListNode*>,
               cmp> pq;
```

The comparator makes it a **Min Heap**:

```cpp
struct cmp {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};
```

---

## Algorithm

```text
1. Put the first node of every non-empty list into Min Heap.

2. While heap is not empty:
   - Take the smallest node.
   - Add it to the result list.
   - If that node has a next node:
       push next node into heap.

3. Return the merged list.
```

---

## Code

```cpp
class Solution {
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*,
                       vector<ListNode*>,
                       cmp> pq;

        // Put first node of every list
        // into the min heap
        for (ListNode* head : lists) {
            if (head != nullptr) {
                pq.push(head);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {

            ListNode* curr = pq.top();
            pq.pop();

            // Add smallest node
            tail->next = curr;
            tail = tail->next;

            // Add next node from same list
            if (curr->next != nullptr) {
                pq.push(curr->next);
            }
        }

        return dummy.next;
    }
};
```

---

## Why Min Heap?

Suppose:

```text
List 1 → 1 → 4 → 5
List 2 → 2 → 3 → 6
List 3 → 0 → 7
```

Currently we only care about:

```text
1, 2, 0
```

The smallest is `0`.

After taking `0`, we only need the next node from that same list:

```text
1, 2, 7
```

So the heap always keeps the **next possible smallest elements**.

---

## Important Pattern

Remember:

```text
K sorted lists
       ↓
First node of every list
       ↓
     Min Heap
       ↓
Take smallest
       ↓
Push its next node
       ↓
Repeat
```

This is called **K-Way Merge**.

The same pattern can be used for:

* Merge K Sorted Arrays
* Merge K Sorted Lists
* Kth Smallest Element in Sorted Lists
* External Sorting

---

## Complexity

Let:

* `K` = number of linked lists
* `N` = total number of nodes

Each node enters and leaves the heap once.

### Time

```text
N nodes × log(K)
= O(N log K)
```

### Space

At most one node from each list is inside the heap:

```text
O(K)
```

So:

```text
Time  = O(N log K)
Space = O(K)
```

## One-Line Revision

> **Put the first node of every sorted list into a Min Heap; repeatedly take the smallest node and push its next node.**
