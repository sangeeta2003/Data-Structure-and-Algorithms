class Solution {
private:
    int fun(int m, int n, int guess) {

        int cnt = 0;

        for(int i = 1; i <= m; i++) {
            cnt += min(n, guess / i);
        }

        return cnt;
    }

public:
    int findKthNumber(int m, int n, int k) {

        int low = 1;
        int high = m * n;
        int res = -1;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            int ans = fun(m, n, mid);

            if(ans < k) {
                low = mid + 1;
            }
            else {
                res = mid;
                high = mid - 1;
            }
        }

        return res;
    }
};