#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int low , int high , int mid){
    int n = arr.size();

    vector<int>temp;
    int left = low , right = mid + 1;
    while(low <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left++]);
        }else{
            temp.push_back(arr[right++]);
        }
    }

    while(left <= mid)  temp.push_back(arr[left++]);
    while(right <= high)  temp.push_back(arr[right++]);

    for(int i = low ; i <= high ; i++){
        arr[i] = temp[i - low];
    }


}

void merge_sort(vector<int>& arr, int low , int high ){
    if(low >= high) return;
    int mid = (low + high) / 2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1, high);
    merge(arr,low,high,mid);

}


int main() {
    vector<int> arr = {5, 2, 8, 4, 1};
    int n = arr.size();

    cout << "Before merge sort:\n";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    merge_sort(arr, 0, n - 1);

    cout << "After merge sort:\n";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}