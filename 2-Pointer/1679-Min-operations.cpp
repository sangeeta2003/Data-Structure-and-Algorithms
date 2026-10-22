class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = n -1 ;
        int sum = 0;
        while(i < j){
            sum = nums[i] + nums[j];
            if(sum == k){
                cnt++;
                i++;
                j--;
            }
            else if(sum < k)i++;
            else j--;
        }
        return cnt;
    }
};