#include <bits/stdc++.h>
using namespace std;


class Solution{
    public :
   void nextPermutation(vector<int>& arr){
        int n = arr.size();
int index = -1;
for(int i = n - 2 ; i >= 0 ; i--){
    if(arr[i] < arr[i +1]){
        index = i;
        break;

    }
}
if(index == -1){
    reverse(arr.begin(), arr.end());
    return ;
}
for(int i = n-1; i > index; i--){
    if(arr[i] > arr[index]){
        swap(arr[i], arr[index]);
        break;
    }
}
reverse(arr.begin() + index + 1 , arr.end());
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

    sol.nextPermutation(arr);
    for(int nums : arr){
        cout << nums;
    }
    return 0;
}
