# Combination Sum

## Problem

Given an array `candidates` and a `target`, find all unique combinations where the chosen numbers add up to `target`.

Each number can be used **unlimited times**.

### Example

```text
candidates = [2,3,6,7]
target = 7
```

Valid combinations:

```text
[2,2,3] → 2 + 2 + 3 = 7
[7]     → 7 = 7
```

Answer:

```text
[[2,2,3],[7]]
```

## Approach: Recursion + Backtracking

At every index, we have two choices:

### 1. Not Take

Skip the current number and move to the next index.

```text
idx → idx + 1
```

### 2. Take

Choose the current number and keep the **same index** because the number can be reused.

```text
idx → idx
```

After the recursive call, remove the number using `pop_back()` to try another combination.

## Example Calculation

For:

```text
[2,3,6,7], target = 7
```

One path:

```text
2
→ 2
→ 2
→ 2

sum = 8
❌ greater than target
```

Another path:

```text
2 → 2 → 3

2 + 2 + 3 = 7
✅ store [2,2,3]
```

Another path:

```text
7

7 = target
✅ store [7]
```

## Important Points

* `sum == target` → store the current combination and stop.
* `sum > target` → stop the current path.
* `idx == n` → no more elements, so stop.
* **Take:** keep `idx` unchanged because elements can be reused.
* **Not take:** move to `idx + 1`.
* `pop_back()` performs the backtracking.

## Complexity

Let `T` be the target and `n` be the number of candidates.

The recursion explores many possible combinations, so the time complexity is approximately:

```text
O(number of possible combinations)
```

Space complexity:

```text
O(target)
```

for the recursion depth and current combination.
