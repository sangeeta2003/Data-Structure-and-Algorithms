#include <bits/stdc++.h>
using namespace std;


class Solution{
    public :
    int sumequalsk(vector<int>& arr, int k){
        int n = arr.size();
        unordered_map<int,int>mpp;
        int prefixSum = 0;
        int cnt = 0;
        mpp[0] = 1;
        for(int i =0 ; i < n ;i++){
            prefixSum += arr[i];
            int remove = prefixSum - k;
            if(mpp.find(remove) != mpp.end()){
                cnt += mpp[remove];
            }
            mpp[prefixSum]++;
        }

return cnt;
    }
};
int main(){
    Solution sol;
    int n ;
    cout << "Enter value of n";
    cin >> n;
    int k;
     cout << "Enter value of k";
    cin >> k;

    vector<int>arr(n);
    cout << "Enter value of array";
    for(int i = 0 ; i < n ;i++){
cin >> arr[i];

    }
   int result = sol.sumequalsk(arr, k);
cout << result;
    
    return 0;

}