#include <bits/stdc++.h>
using namespace std;

int largeElem(vector<int>& arr){
    int n = arr.size();
    int large = INT_MIN;
    for(int i = 0 ; i < n ;i++){
        if(arr[i] > large){
            large = arr[i];
        }
    }
    return large;
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
    int largest = largeElem(arr);
    cout << "Largest element is: " << largest << endl;

    return 0;

}