55. Jump Game
Problem

Given an integer array nums, where each element represents the maximum jump length from that index, return true if the last index is reachable; otherwise, return false.

Approach: Greedy
Maintain reach, the farthest index reachable so far.
Iterate through the array.
If i > reach, the current index cannot be reached, so return false.
Otherwise, update reach = max(reach, i + nums[i]).
If the loop completes, return true.
Complexity Analysis
Time Complexity: O(n), where n is the size of the array.
Space Complexity: O(1), as only a constant amount of extra space is used.