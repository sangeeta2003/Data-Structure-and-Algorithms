class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int ans = INT_MIN;
        int n = nums.size();
        int sum =0;
        for(int i = 0 ; i < k;i++){
sum += nums[i];
        }
        ans = sum;
        for(int right = k ; right < n ;right++){
            sum += nums[right];
            sum -= nums[right - k];
             ans = max(ans,sum);
        }
        
        return (double) ans / k;

    }
};