class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int zero = 0;
        int one  =0;
        unordered_map<int,int>f;
        int res =0;
        for(int i = 0 ; i < n ;i++){
            if(nums[i] == 0){
                zero++;
            }
            else{
                one++;
            }
            int diff = zero - one;
            if(diff == 0){
                res = max(res,i+1);
            }
            if(f.find(diff) == f.end()){
                f[diff] = i;
            }else{
                int ind = f[diff];
                int len = i - ind;
                res  = max(res,len);
            }
        }
        return res;
    }
};