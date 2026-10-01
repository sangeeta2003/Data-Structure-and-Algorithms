#include <bits/stdc++.h>
using namespace std;


class Solution{
    public :
    void rotateArray(vector<int>& arr){
        int n = arr.size();
        int start = arr[0];
        for(int i = 1; i < n ; i++){
            arr[i - 1] = arr[i];
        }
        arr[n - 1] = start;
    }
};
int main(){
    Solution sol;
     int n ;
    cout << "Enter the n value :";
    cin >> n;
    vector<int>arr(n);
    cout << "Enter array elements :";
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    sol.rotateArray(arr);
    for(int num : arr){
         cout << num << " ";
    }
    return 0;
}