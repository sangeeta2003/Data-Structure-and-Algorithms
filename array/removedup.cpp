#include <bits/stdc++.h>
using namespace std;

int removeDuplicate(vector<int>& arr){
    int n = arr.size();
    int i = 0 ; 
    for(int j = 1 ; j < n ; j++){
        if(arr[i] != arr[j]){
            arr[i + 1] = arr[j];
            i++;
        }
    }
    return i + 1;
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
  int k = removeDuplicate(arr);

cout << "after removing duplicates :";
for(int i = 0 ; i < k ; i++){
    cout << arr[i] << " ";
}
    return 0;
}