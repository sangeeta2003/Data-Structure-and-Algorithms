class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int preSum = 0;
        int cnt = 0;
        unordered_map<int,int>f;
        f[0] = 1;
        for(int i = 0;i<n;i++){
            preSum += nums[i];
            int rem = preSum - k;
            cnt += f[rem];
            f[preSum]++;
        }
        
        return cnt;
    }
};