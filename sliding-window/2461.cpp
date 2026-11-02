class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long sum =0;
        unordered_map<int,int>freq;
        int left = 0;
        for(int right = 0 ; right < n ;right++){
sum += nums[right];
freq[nums[right]]++;
if(right - left + 1 > k){
    sum -= nums[left];
    freq[nums[left]]--;
    if(freq[nums[left]] == 0) freq.erase(nums[left]);
    left++;
}
if(right - left + 1 == k && freq.size() == k ){
    ans = max(ans,sum);
}
        }
        return ans;
    }
};