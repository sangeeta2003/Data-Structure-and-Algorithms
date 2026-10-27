class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n - 1, '#') + ".");  // walls, then the last cell open
        grid[0] = string(n, '.');  // the first row is all open
        return grid;
    }
};