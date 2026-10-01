#include <bits/stdc++.h>
using namespace std;


class Solution{
    public :
    void reverseArray(vector<int>& arr, int start , int end){
        while(start < end){
swap(arr[start], arr[end]);
start++;
end--;
        }

    }
     vector<int> rotateArray(vector<int>& arr, int k, string direction) {
        int n = arr.size();
        if(n == 0 || k == 0) return arr;

        k = k % n ;
        if(direction == "right"){
reverseArray(arr , 0 , n - 1);
reverseArray(arr, 0 , k -1);
reverseArray(arr, k , n - 1);
        }
        else if(direction == "left"){
reverseArray(arr , 0 , k - 1);
reverseArray(arr, k , n -1);
reverseArray(arr, 0 , n - 1);
        }
          return arr;
     }
   

};
int main(){
Solution sol;
int n , k ;
string direction;
 cout << "Enter array size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter k: ";
    cin >> k;

    cout << "Enter direction (left/right): ";
    cin >> direction;

    arr = sol.rotateArray(arr, k , direction);
     for (int x : arr) cout << x << " ";

    return 0;
}