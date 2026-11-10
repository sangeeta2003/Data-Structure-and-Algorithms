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
    int maxAbsoluteSum(vector<int>& nums) {
        int ans = nums[0];
        int r1 = maxSum(nums);
        int r2 = minSum(nums);
        int r3 = abs(r1);
        int r4 = abs(r2);
        ans = max(ans,max(r3,r4));
return ans;
    }
};