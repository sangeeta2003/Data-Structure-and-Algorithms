class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int>f;
        int n = nums.size();
        int l = 0;
        int sum = 0;
        int maxSum = INT_MIN;
        for(int r= 0 ; r < n ;r++ ){
            f[nums[r]]++;
            sum += nums[r];

        
        while(f[nums[r]] > 1){
            f[nums[l]]--;
            sum -= nums[l];
            l++;
            
            

        }
        maxSum = max(maxSum,sum);
        }
        return maxSum;
      
        
    }
};