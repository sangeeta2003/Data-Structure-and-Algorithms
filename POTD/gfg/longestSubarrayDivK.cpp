class Solution {
  public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        // code here
       int n = arr.size();
       unordered_map<int,int>f;
       f[0] = -1;
       int sum = 0;
       int ans = 0;
       
       for(int i = 0 ; i < n ;i++){
           sum += arr[i];
           
           int rem = sum % k;
            if (rem < 0) rem += k;
           if(f.find(rem) != f.end()){
               ans = max(ans,i - f[rem]);
           }else{
               f[rem] = i;
           }
       }
       return ans;
    }
};