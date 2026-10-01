#include <bits/stdc++.h>
using namespace std;


class Solution{
    public :
    int longestSubarraySum(vector<int>& arr , int k){
        int n = arr.size();
        int l = 0;
        int r = 0;
        int sum = arr[0];
        int maxLen = 0;

        while(r < n){
            while(l <= r && sum > k){
                sum -= arr[l];
                l++;
            }
            if(sum == k){
                maxLen = max(maxLen , r - l + 1);
            }
            r++;
            if(r < n) sum += arr[r];
        }
        return maxLen;
    }

};
int main(){
    Solution sol;
int n;
    cout << "Enter size of array: ";
    cin >> n;

    int k;
    cout << "Enter size of sum: ";
    cin >> k;

    vector<int>arr(n);
    cout << "Enter elements of array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int maxLen = sol.longestSubarraySum(arr , k);
    cout << maxLen;
    return 0;
}