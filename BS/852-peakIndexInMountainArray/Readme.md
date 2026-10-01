852. Peak Index in a Mountain Array

Difficulty: Medium
Topic: Binary Search
Time Complexity: O(log n)
Space Complexity: O(1)

Problem

You are given a mountain array arr.

A mountain array:

Strictly increases up to a peak.
Then strictly decreases.

Return the index of the peak element.

Example
Input:  arr = [0, 2, 1, 0]
Output: 1

The peak element is 2, whose index is 1.

Approach — Binary Search

We don't need to find the maximum by checking every element.

At any index mid, compare:

arr[mid] and arr[mid + 1]
Case 1: arr[mid] < arr[mid + 1]

We are on the increasing side.

       /
      /
     /  ← mid
    /

The peak must be somewhere to the right.

So:

low = mid + 1;
Case 2: arr[mid] > arr[mid + 1]

We are on the decreasing side or mid itself may be the peak.

        /\
       /  \
      /    ← mid

The peak is at mid or somewhere to the left.

So:

high = mid;
// In this we use First occurance when we mid a[mid] > a[mid+1]

Notice that we use high = mid, not mid - 1, because mid itself could be the peak.