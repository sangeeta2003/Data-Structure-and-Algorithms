class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>f;
        int n = nums.size();
        int cnt = 0;
        int preSum = 0;
        f[0] = 1;
        for(int i = 0 ; i < n ;i++){
            preSum += nums[i];
            int rem = preSum % k;
            if(rem < 0) rem = rem + k;
            cnt += f[rem];
            f[rem]++;
        }
        return cnt;
    }
};