# 621. Task Scheduler

## Problem

Given a list of tasks and a cooling time `n`, execute all tasks such that the **same task has at least `n` intervals between two executions**.

An interval can contain:

* A task
* Or an `idle`

Return the **minimum number of intervals** needed.

---

## Example

```text
tasks = [A,A,A,B,B,B]
n = 2
```

We need at least **2 intervals** between the same task.

One valid schedule:

```text
A → B → idle → A → B → idle → A → B
```

Total intervals:

```text
8
```

Answer = **8**

---

## Main Idea

The task that appears the most times is the most important because it creates the biggest restriction.

Here:

```text
A = 3
B = 3
```

Maximum frequency:

```text
maxFreq = 3
```

The most frequent task creates:

```text
maxFreq - 1 = 2
```

gaps.

Each gap needs:

```text
n = 2
```

cooling intervals.

So:

```text
(maxFreq - 1) × (n + 1)
= 2 × 3
= 6
```

The final occurrence of the most frequent task is already included, so add:

```text
+ 1
```

Therefore:

```text
6 + 1 = 7
```

But we also have another task `B` that can fill some idle positions.

The actual schedule becomes:

```text
A B idle
A B idle
A B
```

Therefore:

```text
8 intervals
```

---

## Important Formula

First calculate:

```text
(maxFreq - 1) × (n + 1) + numberOfTasksWithMaxFreq
```

For:

```text
A A A B B B
```

We have:

```text
maxFreq = 3
numberOfTasksWithMaxFreq = 2
n = 2
```

Calculation:

```text
(3 - 1) × (2 + 1) + 2
= 2 × 3 + 2
= 8
```

So answer:

```text
8
```

---

## Why `+ numberOfTasksWithMaxFreq`?

Suppose:

```text
A A A
n = 2
```

Schedule:

```text
A → idle → idle → A → idle → idle → A
```

There are:

```text
3 A's
```

and

```text
2 gaps
```

Calculation:

```text
(maxFreq - 1) × (n + 1) + maxFreq
= 2 × 3 + 1
= 7
```

So we need **7 intervals**.

If two tasks have the same maximum frequency:

```text
A A A
B B B
```

The last group contains both:

```text
A B
```

Therefore we add `2` instead of `1`.

---

## Important Edge Case

Sometimes there are enough different tasks to completely fill the cooling gaps.

Example:

```text
tasks = [A,A,A,B,B,B,C,C,C]
n = 2
```

We can arrange:

```text
A B C A B C A B C
```

No idle time is required.

So the formula gives a minimum structure, but the answer can never be smaller than the total number of tasks.

Therefore:

```text
answer = max(
    total number of tasks,
    (maxFreq - 1) × (n + 1) + numberOfTasksWithMaxFreq
)
```

---

## Example 2

```text
tasks = [A,C,A,B,D,B]
n = 1
```

Frequencies:

```text
A = 2
B = 2
C = 1
D = 1
```

So:

```text
maxFreq = 2
numberOfTasksWithMaxFreq = 2
```

Calculation:

```text
(2 - 1) × (1 + 1) + 2
= 1 × 2 + 2
= 4
```

But there are:

```text
6 tasks
```

Therefore:

```text
answer = max(6, 4)
       = 6
```

A valid arrangement:

```text
A → B → C → D → A → B
```

Answer = **6**

---

## Pattern to Remember

This is a **Greedy + Frequency Counting** problem.

Think:

```text
Most frequent task
        ↓
Creates gaps
        ↓
Cooling time fills gaps
        ↓
Other tasks may fill those gaps
        ↓
Remaining empty positions become idle
```

### Formula

```text
max(
    tasks.size(),
    (maxFreq - 1) × (n + 1) + maxFreqCount
)
```

Where:

* `maxFreq` = highest frequency of any task
* `maxFreqCount` = number of tasks having that highest frequency
* `n` = cooling interval
* `tasks.size()` = total number of tasks
