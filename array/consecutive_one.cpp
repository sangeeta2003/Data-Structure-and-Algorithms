#include <bits/stdc++.h>
using namespace std;


class Solution{
    public :
    int maxConsecutiveOnes(vector<int>& arr){
        int cnt = 0;
        int maxi = INT_MIN;
        int n = arr.size();
        for(int i = 0 ; i < n ; i++){
            if(arr[i] == 1){
                cnt++;
        maxi = max(maxi , cnt);
            }else{
                cnt = 0;
            }
        }
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
    int maxOne = sol.maxConsecutiveOnes(arr);
    cout << maxOne;
    return 0;
}