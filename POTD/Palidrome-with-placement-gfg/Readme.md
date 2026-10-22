# Palindrome with Replacement — GFG

## Problem Statement

Given a string `s` containing lowercase English letters and the character `?`, replace every `?` with a lowercase letter so that the resulting string is a palindrome.

The goal is to minimize the sum of absolute ASCII differences between every pair of adjacent characters.

If it is impossible to form a palindrome, return `-1`.

## Approach

### Step 1: Check mirrored characters

A palindrome reads the same forward and backward. Therefore, characters at indices `i` and `n - 1 - i` must match.

```cpp
int j = n - 1 - i;
```

There are three cases:

- **Both characters are fixed:** If they are different, return `-1`.
- **One character is `?`:** Replace it with the known character.
- **Both characters are `?`:** They can be assigned the same letter later.

### Step 2: Calculate the minimum cost

The cost between adjacent characters is:

\[
|\text{ASCII}(a)-\text{ASCII}(b)|
\]

For example:

- `a → b` costs `1`.
- `a → c` costs `2`.
- `b → b` costs `0`.

We only need to examine the left half of the palindrome, including the middle character.

Skip the `?` characters temporarily and consider the fixed letters in order. For each pair of consecutive fixed letters, add their absolute ASCII difference.

Unknown characters between two fixed letters can be filled with letters that achieve this minimum difference.

### Step 3: Account for palindrome symmetry

Every transition on the left side has a matching transition on the right side. Therefore, multiply the calculated cost by `2`.

## Example

**Input:**

```text
a???c??c????
```

**One optimal palindrome:**

```text
abbbccccbbba
```

ASCII values:

- `a = 97`
- `b = 98`
- `c = 99`

Adjacent differences:

```text
a → b = 1
b → b = 0
b → b = 0
b → c = 1
c → c = 0
c → c = 0
c → c = 0
c → b = 1
b → b = 0
b → b = 0
b → a = 1
```

Total cost:

\[
1+0+0+1+0+0+0+1+0+0+1=4
\]

**Output:**

```text
4
```

## Complexity Analysis

- **Time Complexity:** \(O(n)\), because we scan the string a constant number of times.
- **Auxiliary Space:** \(O(1)\), excluding the input string, when only a constant number of variables are used.

## Key Learning

- Palindrome problems often use two pointers and mirrored indices.
- `n - 1 - i` finds the position that mirrors index `i`.
- Absolute ASCII differences measure the cost between adjacent letters.
- Always check whether fixed mirrored characters conflict before calculating the minimum cost.
