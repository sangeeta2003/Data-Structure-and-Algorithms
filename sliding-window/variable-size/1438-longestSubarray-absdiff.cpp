
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        deque<int>maxDeq,minDeq;
        int l = 0;
        int maxWindow = 0;

        int n = nums.size();

        for(int r = 0 ; r < n ;r++){
            while(!maxDeq.empty() && maxDeq.back() < nums[r])
            maxDeq.pop_back();
            while(!minDeq.empty() && minDeq.back() > nums[r])
            minDeq.pop_back();
maxDeq.push_back(nums[r]);
minDeq.push_back(nums[r]);
while(maxDeq.front() - minDeq.front() > limit){
    if(maxDeq.front() == nums[l])
    maxDeq.pop_front();
    if(minDeq.front() == nums[l])
    minDeq.pop_front();
    l++;
}
maxWindow = max(maxWindow,r - l +1);
        }
        return maxWindow;
    }
};
