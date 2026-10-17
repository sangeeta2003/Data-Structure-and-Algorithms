class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
         if (n == 0) return 0;
        int i = 0;
        int res = 1;
        int j = 1;
       while(j < n){
            if(nums[j] == nums[i]) j++;
            else{
                nums[i+1] = nums[j];
                i++;
                j++;
                res++;
            }
        }
        return res;
        
    }
};