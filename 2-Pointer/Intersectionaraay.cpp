class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        // code here
        int n = a.size();
        int m = b.size();
        int i =0;
        int j = 0;
        vector<int>ans;
        
        while(i < n && j < m){
            if(a[i] == b[j]){
                if (ans.empty() || ans.back() != a[i]) {
                                   ans.push_back(a[i]);
                               }
               
                i++;
                j++;
            }
            else if(a[i] < b[j])i++;
            else j++;
        }
        return ans;
    }
};