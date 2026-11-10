class Solution {
    private:
    int maxSum(vector<int>& nums){
        int n = nums.size();
        int ans1 = nums[0];
        int bestEnding = nums[0];
        for(int i = 1 ; i < n ;i++){
            int r1 = nums[i];
            int r2 = bestEnding + nums[i];
            bestEnding = max(r1,r2);
            ans1 = max(ans1,bestEnding);
        }
        return ans1;
    }
    int minSum(vector<int>& nums){
        int n = nums.size();
        int ans2 = nums[0];
        int bestEnding = nums[0];
        for(int i = 1 ; i < n ;i++){
            int r1 = nums[i];
            int r2 = bestEnding + nums[i];
            bestEnding = min(r1,r2);
            ans2 = min(ans2,bestEnding);
        }
        return ans2;
    }
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum  = nums[0];
        int ans = INT_MIN;
        for(int i = 1 ; i < nums.size() ;i++){
            sum += nums[i];

        }
        int r1 = maxSum(nums);
        int r2 = minSum(nums);
        if(r1 < 0) return r1;
        int rem = sum - r2;
ans = max(rem,r1);
return ans;
    }
};