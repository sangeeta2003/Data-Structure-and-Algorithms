#include <bits/stdc++.h>
using namespace std;


class Solution{
    public :
    vector<int> twoSum(vector<int>& arr, int target){
        int n = arr.size();
        vector<pair<int,int>> afterArr;
        for(int i = 0 ; i < n ;i++){
afterArr.push_back({arr[i], i});
        }
        
        sort(afterArr.begin() , afterArr.end());
        int l = 0;
        int r = n - 1;
        int sum = 0;
        while(l < r){
sum = afterArr[l].first + afterArr[r].first;
if(sum == target) return {afterArr[l].second, afterArr[r].second};
else if(sum > target) r--;
else 
l++;
        }
         return {-1 , -1 };
    
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
    vector<int> ans = sol.twoSum(arr , k);
     cout << "[" << ans[0] << ", " << ans[1] << "]";
    return 0;
}