#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int n){
for(int i = 0 ; i < n ;i++){
    int j = i;
    
       while(j > 0 && arr[j - 1] > arr[j]){ swap(arr[j - 1], arr[j]);

        j--;
       }
    
}
 cout << "After insertion sort: " << "\n";
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
    cout << "Before insertion sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    // Call selection sort
    insertion_sort(arr, n);

    return 0;
}