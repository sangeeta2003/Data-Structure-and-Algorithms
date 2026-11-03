class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_num = *max_element(nums.begin(),nums.end());
        int n = nums.size();
        int cnt = 0;
        for(int i =0 ; i < n ;i++){
            cnt += abs(max_num - nums[i]);
        }
        return cnt;
    }
};