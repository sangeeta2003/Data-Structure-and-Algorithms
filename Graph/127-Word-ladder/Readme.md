# 127. Word Ladder

## Approach: Breadth-First Search (BFS)

* Store all words in an `unordered_set` for efficient lookup.
* If `endWord` is not present in the set, return `0`.
* Start BFS from `beginWord` with a sequence length of `1`.
* For each word, change each character one by one to every letter from `'a'` to `'z'`.
* If a generated word exists in the set, add it to the queue with the sequence length increased by `1`, then erase it from the set to prevent revisiting.
* Restore the original character after checking all replacements.
* If `endWord` is reached, return the current sequence length. If no transformation is possible, return `0`.

## Complexity Analysis

* **Time Complexity:** `O(N × L × 26)`, where `N` is the number of words and `L` is the word length.
* **Space Complexity:** `O(N × L)` for the set and BFS queue.
