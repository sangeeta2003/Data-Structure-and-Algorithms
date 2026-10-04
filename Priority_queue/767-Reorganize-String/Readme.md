# LeetCode 767 - Reorganize String

## Problem

Rearrange the string so that no two adjacent characters are the same. Return `""` if it is impossible.

## Approach

* Count the frequency of each character using `unordered_map`.
* Use a **Max Heap (Priority Queue)** based on frequency.
* Take the two most frequent different characters at a time.
* Decrease their frequencies and put them back into the heap if needed.
* If one character remains with frequency greater than `1`, return `""`.

## Example

```text
Input:  "aab"
Output: "aba"
```

```text
Input:  "aaab"
Output: ""
```

## Complexity

* **Time:** O(n log k)
* **Space:** O(k)

## Key Concept

**Hash Map + Max Heap (Priority Queue)**
