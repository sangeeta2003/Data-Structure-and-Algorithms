#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void revarray(vector<int>& arr, int p1, int p2){
        if(p1 >= p2) return;          // base case
        swap(arr[p1], arr[p2]);       // swap first and last
        revarray(arr, p1+1, p2-1);    // recursive call
    }
};

int main(){
    Solution sol;
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    vector<int> arr;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Original array: ";
    for(int x : arr) cout << x << " ";
    cout << endl;

    sol.revarray(arr, 0, arr.size() - 1); // reverse the array

    cout << "Reversed array: ";
    for(int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
