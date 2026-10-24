
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        int n = arr.size();

        if (n < 2) return {};

        sort(arr.begin(), arr.end());

        int i = 0, j = n - 1;
        int bestDiff = INT_MAX;
        int maxAbsDiff = -1;
        vector<int> ans;

        while (i < j) {
            int sum = arr[i] + arr[j];
            int diff = abs(sum - target);
            int absDiff = arr[j] - arr[i];

            if (diff < bestDiff ||
                (diff == bestDiff && absDiff > maxAbsDiff)) {
                bestDiff = diff;
                maxAbsDiff = absDiff;
                ans = {arr[i], arr[j]};
            }

            if (sum < target) {
                i++;
            } else {
                j--;
            }
        }

        return ans;
    }
};
