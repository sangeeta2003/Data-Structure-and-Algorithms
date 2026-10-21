class Solution {
public:
    int minSubarraySum(vector<int>& arr) {
        int currSum = arr[0];
        int minSum = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            currSum = min(arr[i], currSum + arr[i]);
            minSum = min(minSum, currSum);
        }

        return minSum;
    }
};