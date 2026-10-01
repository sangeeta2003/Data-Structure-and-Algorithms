#include <bits/stdc++.h>
using namespace std;


class Solution{
    public :
    void moveZerodEnd(vector<int>& arr){
        int n = arr.size();
        int j = -1;
        for(int i = 0 ; i < n ;i++){
            if(arr[i] == 0){
                j = i;
                break;
            }
        }
        if(j == -1) return;
for(int i = j + 1 ; i < n ; i++){
    if(arr[i] != 0){
        swap(arr[i],arr[j]);
        j++;
    }
}
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
    sol.moveZerodEnd(arr);
    for(int num : arr){
        cout << num;
    }
    return 0;
}