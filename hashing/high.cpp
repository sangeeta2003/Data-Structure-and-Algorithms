#include <bits/stdc++.h>
using namespace std;

void Frequency(int arr[], int n) {
    unordered_map<int,int> mpp;
    int highestFreq = INT_MIN;
    int lowestFreq = INT_MAX;
    int highestElem, lowestElem;

    // Count frequency of array elements
    for(int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }

    cout << "Element : Frequency" << endl;

    for(auto it : mpp) {
        cout << it.first << " : " << it.second << endl;

        if(it.second > highestFreq) {
            highestFreq = it.second;
            highestElem = it.first;
        }

        if(it.second < lowestFreq) {
            lowestFreq = it.second;
            lowestElem = it.first;
        }
    }

    cout << "Element with highest frequency: " << highestElem << " (" << highestFreq << ")" << endl;
    cout << "Element with lowest frequency: " << lowestElem << " (" << lowestFreq << ")" << endl;
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
