class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int noDel = arr[0];
        int ans = arr[0];
        int Onedel = INT_MIN;
        for(int i = 1; i < n;i++){
            int prevNodel = noDel;
            noDel = max(arr[i] , arr[i] + noDel);
 Onedel = max(prevNodel,
                         Onedel == INT_MIN ? INT_MIN : Onedel + arr[i]);

ans = max(ans,max(noDel,Onedel));
        }
        return ans;
    }
};