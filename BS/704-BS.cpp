#include <bits/stdc++.h>
using namespace std;

int BinarySerach(vector<int>& a, int target){
    int low = 0;
    int high = a.size()-1;
    while(low <= high){
        int mid = (low + high)/ 2;
        if(a[mid] == target) return mid;
        else if(a[mid] < target) low = mid + 1;
        else high = mid -1;

    }
    return -1;
}
int main() {
    vector<int> a = {1, 3, 5, 7, 9, 11};

    cout << BinarySerach(a, 7);

    return 0;
}