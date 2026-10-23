class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>less,equal,greater,ans;
        for(int i = 0 ; i < n ;i++){
            if(nums[i] < pivot){
                less.push_back(nums[i]);
            }
            else if(nums[i] == pivot){
                equal.push_back(nums[i]);
            }else{
                greater.push_back(nums[i]);
            }
        }
        for(int i = 0 ; i < less.size();i++){
            ans.push_back(less[i]);
        }
         for(int i = 0 ; i < equal.size();i++){
            ans.push_back(equal[i]);
        }
         for(int i = 0 ; i < greater.size();i++){
            ans.push_back(greater[i]);
        }
        return ans;
    }
};