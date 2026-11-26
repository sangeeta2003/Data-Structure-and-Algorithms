class Solution {
private:
    bool possible(vector<int>& candies, int mid, long long k) {
        long long cnt = 0;

        for (int candy : candies) {
            cnt += candy / mid;

            if (cnt >= k) return true;
        }

        return false;
    }

public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1;
        int high = *max_element(candies.begin(), candies.end());

        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(candies, mid, k)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};