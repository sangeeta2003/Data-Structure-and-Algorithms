class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       int n= nums.size();
       unordered_set<int>st;
       for(int i = 0 ; i < n ;i++){
        if(st.find(nums[i]) != st.end()) return true;

        st.insert(nums[i]);
        if(st.size() > k){
            st.erase(nums[i-k]);
        }
       }
       return false;
    }
};