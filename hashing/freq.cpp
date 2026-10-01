#include <bits/stdc++.h>
using namespace std;

void Frequency(int arr[], int n) {
unordered_map<int,int>mpp;
for(int i = 0 ; i <= n ;i++){
    mpp[i]++;
}
 cout << "Element : Frequency" << endl;

 for(auto it : mpp){
     cout << it.first << " : " << it.second << endl;
 }
}
int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements of array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Frequency(arr, n);

    return 0;

}