#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n){
    for(int i = 0 ; i <= n- 2 ; i++){
        int mini = i;
        for(int j = i ; j <= n -1 ; j++){
            if(arr[j] < arr[mini]){
                mini = j;

            }
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
     cout << "After selection sort: " << "\n";
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
    selection_sort(arr, n);

    return 0;
}