#include <bits/stdc++.h>
using namespace std;


class Solution{
    public :
    int subarraySum(vector<int>& arr, int k){
        int n = arr.size();
        unordered_map<int,int>mpp;
        int maxLen = 0;
        int sum = 0;
        for(int i = 0 ; i < n ; i ++){
sum += arr[i];
if(sum == k) maxLen = max(maxLen , i + 1);

int rem = sum - k;
if(mpp.find(rem) != mpp.end()){
    int len = i - mpp[rem];
    maxLen = max(maxLen , len);
}
if(mpp.find(sum) == mpp.end()){
    mpp[sum] = i;
}
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
    int maxLen = sol.subarraySum(arr , k);
    cout << maxLen;
    return 0;
}