class Solution {
    private:
    int FirstOccurance(vector<int>& nums,int target){
        int low = 0;
        int high = nums.size()-1;
        int res = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] < target) low = mid + 1;
            else if(nums[mid] > target) high = mid - 1;
            else {
                res = mid;
                high = mid - 1;
            }
        }
        return res;
    }
    private:
    int LastOccurance(vector<int>& nums,int target){
        int low = 0;
        int high = nums.size()-1;
        int res = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] < target) low = mid + 1;
            else if(nums[mid] > target) high = mid - 1;
            else {
                res = mid;
                low = mid + 1;
            }
        }
        return res;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int first = FirstOccurance(nums,target);

        int last = LastOccurance(nums,target);
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    
    }
};