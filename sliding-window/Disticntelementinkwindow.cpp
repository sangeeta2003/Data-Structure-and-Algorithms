class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        vector<int>ans;
        int n = arr.size();
        unordered_map<int,int>mp;
        for(int i = 0 ; i < k;i++){
            mp[arr[i]]++;
        }
        ans.push_back(mp.size());
        for(int right = k ; right < n ;right++){
            mp[arr[right]]++;
            mp[arr[right - k]]--;
            if(mp[arr[right - k]] == 0){
                mp.erase(arr[right-k]);
            }
            ans.push_back(mp.size());
        }
        return ans;
    }
};