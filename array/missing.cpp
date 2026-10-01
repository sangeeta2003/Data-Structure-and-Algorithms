#include <bits/stdc++.h>
using namespace std;


class Solution{
    public :
    int missingNumber(vector<int>& arr){
        int n = arr.size();
        int sum1 = 0;
        int total_sum = n * (n + 1) / 2;
        for(int i = 0 ; i < n ; i++){
  sum1 += arr[i];
        }
        
        int missingNumber = total_sum - sum1;
 return missingNumber;

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
    int missingNumber = sol.missingNumber(arr);
    cout << missingNumber;
    return 0;
}
