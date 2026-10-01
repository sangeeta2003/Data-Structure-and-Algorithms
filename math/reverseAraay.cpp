#include <bits/stdc++.h>
using namespace std;


void isReverse(int arr[], int n){
    reverse(arr, arr + n);

}
int main(){
    int n ;
    cout << "enter value of n : ";
    cin >> n;

    int arr[n];
    for(int i = 0 ; i < n ; i++){
        cout << "enter values of array :" ;
        cin >> arr[i];

    }
    isReverse(arr,n);
     cout << "Reversed array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }


}