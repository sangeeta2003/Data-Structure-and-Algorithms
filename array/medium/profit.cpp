#include <bits/stdc++.h>
using namespace std;


class Solution{
    public :
    int cntProfit(vector<int>& arr){
int n = arr.size();
int maxProfit = INT_MIN;
int minPrice = arr[0];
for(int i = 0 ; i < n ;i++){
    if(minPrice > arr[i]){
        minPrice = arr[i];
    }else{
        maxProfit = max(maxProfit, arr[i] - minPrice);
    }
}
return maxProfit;
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

    int maxProfit = sol.cntProfit(arr);
    cout << maxProfit;
    return 0;
    }