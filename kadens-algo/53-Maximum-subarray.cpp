class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int bestEnding = nums[0];
        int ans = nums[0];
        for(int i= 1 ; i < n ;i++){
            int r1 = nums[i];
            int r2 = bestEnding + nums[i];
            bestEnding = max(r1,r2);
            ans = max(ans,bestEnding);
        }
        return ans;
    }
};