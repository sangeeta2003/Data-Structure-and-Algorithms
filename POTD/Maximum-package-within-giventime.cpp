class Solution {
public:
    int maxPackages(vector<int>& arr, int totalTime) {
        int n = arr.size();

        int k = min(totalTime, n);

        int left = 0;
        int sum = 0;
        int maxSum = INT_MIN;

        for (int right = 0; right < n; right++) {

            sum += arr[right];

            if (right - left + 1 > k) {
                sum -= arr[left];
                left++;
            }

            if (right - left + 1 == k) {
                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};