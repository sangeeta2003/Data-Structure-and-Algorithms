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



2)
# Minimum Operations to Sort a Permutation

## 1. Main Idea

The code checks two possible patterns:

1. **Ascending circular pattern:** Every element is one greater than the previous element, wrapping from `n - 1` back to `0`.
2. **Descending circular pattern:** Every element is one smaller than the previous element, wrapping from `0` back to `n - 1`.

If one of these patterns matches the entire array, the code calculates the answer. Otherwise, it returns `-1`.

## 2. Step 1: Initialize the variables

```cpp
int n = nums.size();

int asc = 1;
int dsc = 1;
```

- `n` stores the size of the array.
- `asc` counts how many elements belong to the ascending pattern.
- `dsc` counts how many elements belong to the descending pattern.

Both counters start at `1` because we initially count the first element.

## 3. Step 2: Check the ascending pattern

```cpp
if (nums[i] == (nums[i - 1] + 1) % n) {
    asc++;
}
```

This checks whether the current element is one greater than the previous element, allowing circular wraparound.

### Example

Suppose:

```text
nums = [1, 2, 3, 0]
n = 4
```

| Previous | Current | Expected value | Match? |
|---:|---:|---:|---|
| 1 | 2 | `(1 + 1) % 4 = 2` | Yes |
| 2 | 3 | `(2 + 1) % 4 = 3` | Yes |
| 3 | 0 | `(3 + 1) % 4 = 0` | Yes |

Every comparison matches, so `asc = 4`.

### Why do we use `% n`?

The modulo operator allows the sequence to wrap around.

For example:

```cpp
(3 + 1) % 4 == 0
```

Without `% n`, the expected value would be `4` instead of `0`.

## 4. Step 3: Check the descending pattern

```cpp
if (nums[i - 1] == (nums[i] + 1) % n) {
    dsc++;
}
```

This checks whether the previous element is one greater than the current element, again allowing circular wraparound.

For example:

```text
nums = [3, 2, 1, 0]
```

The comparisons are:

- `3 == (2 + 1) % 4` → true
- `2 == (1 + 1) % 4` → true
- `1 == (0 + 1) % 4` → true

Therefore, `dsc = 4`.

## 5. Step 4: Calculate the answer for ascending order

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

If `asc == n`, the complete array follows the ascending circular pattern.

- `first` stores the first element.
- If `first == 0`, the array is already in the required sorted order, so return `0`.
- Otherwise, calculate two candidate operation counts.

For example, if `n = 5` and `first = 2`:

```text
option1 = 5 - 2 = 3
option2 = 2 + 2 = 4
```

The answer is:

```cpp
min(3, 4) = 3;
```

The `min()` function chooses the smaller candidate.

## 6. Step 5: Calculate the answer for descending order

```cpp
if (dsc == n) {
    int last = nums[n - 1];

    int option1 = n - last;
    int option2 = last;

    return min(option1, option2) + 1;
}
```

If `dsc == n`, the complete array follows the descending circular pattern.

- `last` stores the last element.
- `option1` calculates `n - last`.
- `option2` is equal to `last`.
- `min()` chooses the smaller candidate, and the code adds `1`.

For example, if `n = 5` and `last = 2`:

```text
option1 = 5 - 2 = 3
option2 = 2

answer = min(3, 2) + 1
       = 3
```

**Important:** These formulas depend on the operations allowed by the original problem. The code alone does not explain why these candidate counts are valid.

## 7. Step 6: If neither pattern matches

```cpp
return -1;
```

If neither counter reaches `n`, the array does not match either pattern, so the code returns `-1`.

## 8. Complexity Analysis

- **Time Complexity:** \(O(n)\) — the loop checks each adjacent pair once.
- **Auxiliary Space:** \(O(1)\) — only a few variables are used.

## 9. What to Remember

- `asc` checks the ascending circular pattern.
- `dsc` checks the descending circular pattern.
- `% n` allows wraparound from the end to the beginning.
- `min(a, b)` selects the smaller candidate.
- The final formulas must be understood using the problem's specific allowed operations.
