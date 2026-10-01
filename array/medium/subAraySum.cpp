#include <bits/stdc++.h>
using namespace std;


class Solution{
    public :
    int sunArraySum(vector<int>& arr){
        int n = arr.size();
        int maxi = 0;
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
sum += arr[i];
if(sum > maxi){
maxi = max(sum , maxi);
}

        }
        if(sum < 0) return sum = 0 ;
        return maxi;
    }

};
int main(){


    Solution sol;
     int n;
    cout << "Enter size of array: ";
    cin >> n;

   

    vector<int>arr(n);
    cout << "Enter elements of array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxSum = sol.sunArraySum(arr);
    cout << maxSum;
    return 0;
}