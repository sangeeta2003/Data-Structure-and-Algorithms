class Solution {
public:
    bool isPossible(int n, int m, string& s) {
        int row = 0, col = 0;
        int minRow = 0, maxRow = 0;
        int minCol = 0, maxCol = 0;

        for (char c : s) {
            if (c == 'L') col--;
            else if (c == 'R') col++;
            else if (c == 'D') row--;
            else if (c == 'U') row++;

            minRow = min(minRow, row);
            maxRow = max(maxRow, row);
            minCol = min(minCol, col);
            maxCol = max(maxCol, col);
        }

        return (maxRow - minRow < n) &&
               (maxCol - minCol < m);
    }
};