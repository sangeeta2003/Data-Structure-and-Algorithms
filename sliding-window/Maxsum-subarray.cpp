class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int sum = 0;
        int maxSum = INT_MIN;
        int n = arr.size();
        for(int i = 0 ; i < k;i++){
            sum += arr[i];
        }
        maxSum = sum;
        for(int j = k ; j < n ;j++){
            sum += arr[j];
          
            sum -= arr[j-k];
              maxSum = max(sum,maxSum);
            
        }
        return maxSum;
    }
};