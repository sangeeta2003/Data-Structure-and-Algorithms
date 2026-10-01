#include <bits/stdc++.h>
using namespace std;


class Solution{
    public :
    int search(vector<int>& arr, int target){
        int n = arr.size();
        for(int i = 0 ; i < n ;i++){
            if(arr[i] == target){
                return i;
            }
        }
        return -1;
    }

};
int main(){
    Solution sol;
    int target;
    cout << "Enter target: ";
    cin >> target;
     int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int>arr(n);
    cout << "Enter elements of array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int point = sol.search(arr, target);
    cout << point;
    return 0;
}