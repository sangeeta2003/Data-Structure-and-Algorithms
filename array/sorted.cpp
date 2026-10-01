#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int>& arr){
    int n = arr.size();
    for(int i =  0 ; i < n ;i++){
        if(arr[i + 1] < arr[i]) return false;
    }
    return true;
}
int main(){
    
    int n ;
    cout << "Enter the n value :";
    cin >> n;
    vector<int>arr(n);
    cout << "Enter array elements :";
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
   if(isSorted(arr) == true) cout << "Array is sorted";
   else cout<< "Array is not sorted";

    return 0;
}