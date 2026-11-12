class Solution {
public:
    int maxRectSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int maxi = INT_MIN;

        for(int cstart = 0; cstart < m; cstart++) {

            vector<int> temp(n, 0);

            for(int cend = cstart; cend < m; cend++) {

                // Add current column to previous columns
                for(int i = 0; i < n; i++) {
                    temp[i] += mat[i][cend];
                }

                // Kadane's Algorithm
                int sum = 0;

                for(int i = 0; i < n; i++) {
                    sum = max(temp[i], sum + temp[i]);
                    maxi = max(maxi, sum);
                }
            }
        }

        return maxi;
    }
};