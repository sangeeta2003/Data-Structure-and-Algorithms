
class Solution {
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};

    bool Valid(int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return false;
        return true;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;
        int time = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    grid[i][j] = -2;
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        while (!q.empty() && fresh > 0) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                pair<int, int> s = q.front();
                q.pop();

                int r = s.first;
                int c = s.second;

                for (int k = 0; k < 4; k++) {
                    int row = r + x[k];
                    int col = c + y[k];

                    if (Valid(row, col, n, m) &&
                        grid[row][col] == 1) {
                        q.push({row, col});
                        grid[row][col] = -2;
                        fresh--;
                    }
                }
            }

            time++;
        }

        if (fresh > 0) return -1;
        return time;
    }
};