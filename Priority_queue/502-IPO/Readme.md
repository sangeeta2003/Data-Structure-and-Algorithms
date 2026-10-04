# 502. IPO

## Problem

Choose at most `k` projects to maximize the final capital.

Each project has:

* `capital[i]` → minimum capital required
* `profits[i]` → profit earned after completing it

Start with initial capital `w`.

## Approach

* Store each project as `{capital, profit}`.
* Sort projects by required capital.
* Use a **Max Heap** to store profits of all currently affordable projects.
* For each of the `k` projects:

  1. Add all affordable projects to the heap.
  2. Select the project with maximum profit.
  3. Add its profit to `w`.

## Complexity

* Time: **O(n log n + k log n)**
* Space: **O(n)**

## Example

Input:

```text
k = 2
w = 0
profits = [1,2,3]
capital = [0,1,1]
```

Output:

```text
4
```

The best projects are selected to maximize the final capital.
