# 630. Course Schedule III

## Problem

You are given courses:

```text
[duration, lastDay]
```

* `duration` = number of days required to complete the course.
* `lastDay` = the course must be completed on or before this day.

You can take only **one course at a time**.

Goal: **Take the maximum number of courses.**

---

## Main Idea

This is a **Greedy + Max Heap** problem.

### Step 1: Sort courses

Sort courses by their `lastDay` in increasing order.

Why?

We should consider courses with **earlier deadlines first**.

---

### Step 2: Keep track of total time

Let:

```text
time = total duration of selected courses
```

For every course:

```text
time += duration
```

If:

```text
time <= lastDay
```

the course can be kept.

If:

```text
time > lastDay
```

we have exceeded the deadline.

---

## Important Greedy Trick

When we exceed a deadline, don't simply remove the current course.

Instead:

> Remove the course with the **largest duration** among the courses selected so far.

Why?

Because removing the longest course gives us the **maximum amount of free time**, while losing only one course.

A **max heap** stores the durations of selected courses.

---

# Example

```text
courses =
[[100,200],
 [200,1300],
 [1000,1250],
 [2000,3200]]
```

Sort by deadline:

```text
[100,200]
[1000,1250]
[200,1300]
[2000,3200]
```

---

### Course 1

```text
duration = 100
deadline = 200
```

Current time:

```text
0 + 100 = 100
```

Since:

```text
100 <= 200
```

Keep it.

Heap:

```text
[100]
```

Selected courses:

```text
1
```

---

### Course 2

```text
duration = 1000
deadline = 1250
```

Current time:

```text
100 + 1000 = 1100
```

Since:

```text
1100 <= 1250
```

Keep it.

Heap:

```text
[1000, 100]
```

Selected courses:

```text
2
```

---

### Course 3

```text
duration = 200
deadline = 1300
```

Current time:

```text
1100 + 200 = 1300
```

Since:

```text
1300 <= 1300
```

Keep it.

Heap:

```text
[1000, 200, 100]
```

Selected courses:

```text
3
```

---

### Course 4

```text
duration = 2000
deadline = 3200
```

Current time:

```text
1300 + 2000 = 3300
```

But:

```text
3300 > 3200
```

We are late.

So remove the **largest duration** from the heap.

Largest duration:

```text
2000
```

Remove it:

```text
3300 - 2000 = 1300
```

Now:

```text
time = 1300
```

The course we just considered is removed.

Selected courses remain:

```text
100 + 1000 + 200 = 1300
```

Number of courses:

```text
3
```

Answer:

```text
3
```

---

# Why Remove the Largest Course?

Suppose we selected:

```text
[100, 1000, 200]
```

Total:

```text
1300
```

If we need to remove one course, compare:

```text
Remove 100  → time = 1200
Remove 200  → time = 1100
Remove 1000 → time = 300
```

Removing `1000` gives us the most available time.

So we can potentially fit more courses later.

That's why we use a **max heap**.

---

# Important Pattern

Remember this:

```text
Sort by deadline
       ↓
Add course duration
       ↓
Check deadline
       ↓
If late
       ↓
Remove longest course
       ↓
Continue
```

### Data structure

```text
Max Heap
```

The heap stores:

```text
duration of selected courses
```

So:

```text
pq.top()
```

gives the **largest duration**.

---

# Why Sorting by Deadline?

Example:

```text
Course A → deadline 100
Course B → deadline 500
```

We should consider A first because it has the tighter deadline.

So sort:

```text
lastDay ↑
```

---

# Complexity

Sorting:

```text
O(n log n)
```

Each course can be inserted/removed from the heap:

```text
O(log n)
```

Overall:

```text
O(n log n)
```

Space:

```text
O(n)
```

---

# Key Takeaway

This problem uses the greedy idea:

> **Always process the earliest deadline first, and whenever we become late, remove the longest course.**

### Remember:

```text
Deadline → Sort
Duration → Max Heap
Late → Remove Maximum Duration
Goal → Maximum Number of Courses
```
