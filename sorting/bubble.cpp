#include <bits/stdc++.h>
using namespace std;

void Bubble_sort(int arr[], int n){
    for(int i = n -1 ; i >= 0 ; i--){
        for(int j = 0 ; j < n ; j++){
            if(arr[j + 1] < arr[j]) swap(arr[j+1], arr[j]);
        }
    }
     cout << "After bubble sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    // Initialize array
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print array before sorting
    cout << "Before selection sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    // Call selection sort
    Bubble_sort(arr, n);

    return 0;
}