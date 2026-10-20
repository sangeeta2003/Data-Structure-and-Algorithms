class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int cnt =0;
        sort(nums.begin(),nums.end());
        for(int k = n -1 ; k >= 2 ;k--){
            int i = 0;
            int j = k -1;
            while(i < j){
                int sum = nums[i] + nums[j];
                if(sum > nums[k]){
                    cnt += j - i;
                    j--;
                }else{
                    i++;
                }
            }
        }
        return cnt;
    }
};