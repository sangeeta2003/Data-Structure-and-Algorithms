class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int>res;
        for(int i = 0 ; i < n;i++){
            int squ = nums[i] * nums[i];
            res.push_back(squ);
        }
        sort(res.begin(),res.end());
        return res;
    }
};