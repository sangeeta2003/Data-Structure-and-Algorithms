# Unique Paths

## Approach
- Use Dynamic Programming with a 2D DP table.
- Initialize all cells with `0` and set the destination cell to `1`.
- Traverse the grid from bottom-right to top-left.
- Calculate `dp[i][j] = dp[i+1][j] + dp[i][j+1]`.
- Return `dp[0][0]`.

## Complexity
- **Time:** O(m × n)
- **Space:** O(m × n)

## Language
C++