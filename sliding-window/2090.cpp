class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans(n,-1);
        int windowSize = 2 * k + 1;
        if(n < windowSize) {
            return ans;
        }
        long long sum = 0;
        for(int i = 0 ; i < windowSize;i++){
sum += nums[i];
        }
        ans[k] = sum / windowSize;
        for(int right = windowSize ; right < n ;right++){
            sum += nums[right];
            sum -= nums[right - windowSize];
            int center = right - k;
            ans[center] = sum / windowSize;
        }
        return ans;
    }
};