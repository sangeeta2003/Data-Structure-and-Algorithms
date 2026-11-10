class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n= nums.size();
        int maxEnding = nums[0];
        int minEnding = nums[0];
        int ans = nums[0];
        for(int i= 1 ; i < n ;i++){
            int r1 = nums[i];
            int r2 = nums[i] * minEnding;
            int r3 = nums[i] * maxEnding;
            maxEnding = max(r1,max(r2,r3));
            minEnding = min(r1,min(r2,r3));
            ans = max(ans,max(minEnding,maxEnding));
        }
        return ans;
    }
};