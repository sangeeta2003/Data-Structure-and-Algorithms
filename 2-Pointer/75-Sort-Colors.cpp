class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int mid = 0;
        while( low <= high && mid <= high){
if(nums[mid] == 0){
    swap(nums[mid],nums[low]);
    low++;
    mid++;
}
else if(nums[mid] == 1){
    mid++;
}else{
    swap(nums[mid],nums[high]);
    high--;
}
        }
    }
};