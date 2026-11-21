class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n,-1);

        stack<int>st;
        for(int i = 0 ; i < n * 2 ;i++){
            int idx = i % n ;
            while(!st.empty() && nums[idx] > nums[st.top()]){
                res[st.top()] = nums[idx];
                st.pop();
            }
            if(i < n){
                st.push(idx);
            }
           
        }
         return res;
    }
};