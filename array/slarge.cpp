#include <bits/stdc++.h>
using namespace std;

int slargest(vector<int>& arr){
    int n = arr.size();
    int largest = INT_MIN;
    int slargest = INT_MIN;

    for(int i = 0 ; i < n ;i++){
        if(arr[i] > largest){
             slargest = largest;
            largest = arr[i];
           
        }
        if(arr[i] > slargest && arr[i] != largest){
            slargest = arr[i];
        }

    }
    return slargest;
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
    int secondlargest = slargest(arr);
    cout << "Second Largest element is: " << secondlargest << endl;

    return 0;

}