class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int sum = 0;
        for(int i = 0 ; i < n ;i++){
            sum += nums[i];
        }
        for(int i = 0 ; i < n;i++){
            
             r = sum - l - nums[i];
        if(l == r) return i;
         l += nums[i];
        }
       
       
        return -1;
        
    }
};