# Letter Combinations of a Phone Number

## Problem

Given digits from `2` to `9`, generate all possible letter combinations using the phone keypad.

Example:

```text
digits = "23"

2 → abc
3 → def
```

Output:

```text
["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

## Approach: Backtracking

For each digit:

1. Get its possible letters.
2. Choose one letter.
3. Move to the next digit.
4. When all digits are processed, store the combination.
5. Remove the last letter and try another choice.

### Example: `"23"`

```text
        ""
     /   |   \
    a    b    c
   /|\  /|\  /|\
  d e f d e f d e f
```

This gives:

```text
ad ae af
bd be bf
cd ce cf
```

## Important Pattern

```text
choose
   ↓
recursive call
   ↓
backtrack (remove choice)
```

`pop_back()` is used to undo the previous choice.

## Complexity

If each digit has at most 4 letters:

**Time:** `O(4^n × n)`
**Space:** `O(n)` recursion depth, excluding the output.
