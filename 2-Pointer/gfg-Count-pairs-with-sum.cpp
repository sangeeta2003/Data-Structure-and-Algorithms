// for duplicates we allowed so use map othewise 2 -pointer


class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Code here
       unordered_map<int,int>mp;
       int cnt =0;
       for(int i = 0 ; i < arr.size();i++){
           int required = target - arr[i];
           if(mp.find(required) != mp.end()){
               cnt += mp[required];
           }
           mp[arr[i]]++;
       }
       return cnt;
    }
};