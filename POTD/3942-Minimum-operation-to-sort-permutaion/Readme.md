# Minimum Operations to Sort a Permutation

## Problem Overview

Given a permutation `nums` of length `n`, determine the minimum number of operations required to sort it according to the problem's allowed operations.

The solution checks whether the permutation follows a circular ascending or descending pattern. Depending on the pattern, it calculates the answer using the first or last element.

If neither pattern matches, it returns `-1`.

> **Note:** The exact meaning of an operation depends on the original problem statement. The formulas below should be understood in the context of the operations allowed by that problem.

## Approach

### Step 1: Initialize counters

```cpp
int asc = 1;
int dsc = 1;
```

- `asc` counts the elements participating in the circular ascending pattern.
- `dsc` counts the elements participating in the circular descending pattern.

Both start at `1` because the first element is initially counted.

### Step 2: Check the circular ascending pattern

```cpp
if (nums[i] == (nums[i - 1] + 1) % n) {
    asc++;
}
```

Each element should be one greater than the previous element, with circular wraparound.

The modulo operator `% n` allows the sequence to wrap from `n - 1` back to `0`.

For example, when `n = 4`:

```text
0 → 1 → 2 → 3 → 0
```

Because `(3 + 1) % 4 = 0`, the circular transition is valid.

If every adjacent pair satisfies this condition, `asc == n`.

### Step 3: Check the circular descending pattern

```cpp
if (nums[i - 1] == (nums[i] + 1) % n) {
    dsc++;
}
```

This checks the reverse direction: each previous element should be one greater than the current element, using circular wraparound.

For example:

```text
3 → 2 → 1 → 0
```

If every adjacent pair satisfies the descending condition, `dsc == n`.

### Step 4: Calculate the answer for the ascending pattern

```cpp
if (asc == n) {
    int first = nums[0];

    if (first == 0) {
        return 0;
    }

    int option1 = n - first;
    int option2 = first + 2;

    return min(option1, option2);
}
```

If the entire permutation follows the ascending circular pattern:

- Store the first element in `first`.
- If `first == 0`, the permutation is already in the required sorted order, so return `0`.
- Otherwise, calculate two possible operation counts:
  - `option1 = n - first`
  - `option2 = first + 2`
- Return the smaller count.

The `min()` function selects the smaller of the two possible counts.

### Step 5: Calculate the answer for the descending pattern

```cpp
if (dsc == n) {
    int last = nums[n - 1];

    int option1 = n - last;
    int option2 = last;

    return min(option1, option2) + 1;
}
```

If the entire permutation follows the descending circular pattern:

- Store the last element in `last`.
- Calculate the two candidate counts.
- Return the smaller count plus one.

The extra `+1` is part of the formula used by this solution and must be justified by the allowed operations in the original problem.

### Step 6: Handle invalid patterns

```cpp
return -1;
```

If neither the ascending nor descending pattern covers all elements, return `-1`.

## Important Concepts

### 1. Modulo operator

The expression:

```cpp
(a + 1) % n
```

wraps the value back to `0` when it reaches `n`.

For example, `(2 + 1) % 3 = 0`.

### 2. Counting valid adjacent pairs

Each successful comparison increases a counter by one. Since the counter starts at `1`, reaching `n` means all `n - 1` adjacent comparisons succeeded.

### 3. Choosing the minimum

```cpp
min(option1, option2)
```

Returns the smaller of two candidate operation counts.

## Complexity Analysis

- **Time Complexity:** \(O(n)\), because the loop examines each adjacent pair once.
- **Auxiliary Space:** \(O(1)\), because only a constant number of variables are used.

## Key Takeaways

- Use modulo to detect circular sequences.
- Check both ascending and descending patterns.
- Use counters to verify that the complete permutation follows a pattern.
- Compare candidate operation counts with `min()`.
- Understand the permitted operations before deriving the final formulas.
