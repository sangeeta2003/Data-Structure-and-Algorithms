class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        int k = 0;
        int el = nums[0];
        int cnt = 1;
        nums[k++] = nums[0];
        for(int i = 1 ; i < n;i++){
            if(nums[i] == el){
                cnt++;
                if(cnt <= 2){
                    nums[k++] = nums[i];

                }
               
            }
                else{
                    el = nums[i];
                    cnt = 1;
                    nums[k++] = nums[i];
                }
            
        }
        return k;
    }
};