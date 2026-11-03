class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        // in this deque index are stored
vector<int>res;
int n = nums.size();

for(int i= 0 ; i < n ;i++){
     // Remove indices out of the current window
     if(!dq.empty() && dq.front() <= i - k){
        dq.pop_front();
     }
     // Maintain decreasing order in deque
     while(!dq.empty() && nums[i] > nums[dq.back()] ){
        dq.pop_back();
     }
     dq.push_back(i); // add current index
 // Add the front value to result once we reach window size k
 if(i >= k - 1){
    res.push_back(nums[dq.front()]);
 }
}
return res;
    }
};