# 301. Remove Invalid Parentheses

**Difficulty:** Hard
**Language:** C++

## Problem

Remove the minimum number of invalid parentheses from a string and return all possible valid strings.

## Approach

Use **DFS + Backtracking**.

1. Count how many `(` and `)` need to be removed.
2. Try two choices for every parenthesis:

   * Remove it.
   * Keep it.
3. Keep `)` only when there is a matching `(`.
4. Use `unordered_set` to avoid duplicate answers.
5. Store only valid strings with the minimum removals.

## Example

### Input

```text
s = "()())()"
```

### Output

```text
["(())()", "()()()"]
```

We remove only **one `)`**, which is the minimum required.

### Another Example

```text
Input:  s = ")("
Output: [""]
```

Both parentheses are invalid, so both are removed.

## Complexity

* **Time:** O(2^n · n)
* **Space:** O(2^n · n)

## Key Idea

Generate all possibilities using backtracking, but remove only the minimum number of invalid parentheses and keep only valid results.
