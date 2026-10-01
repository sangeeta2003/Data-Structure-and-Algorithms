#include <bits/stdc++.h>
using namespace std;


class Solution{
    public :
    void sortedZero(vector<int>& arr){
        int n = arr.size();
        int low = 0;
        int mid = 0 , high = n - 1;
        while(mid <= high){
            if(arr[mid] == 0){
                swap(arr[mid], arr[low]);
                low++;
                mid++;
            }
            else if(arr[mid] == 1){
                mid++;
            }
            else{
                swap(arr[mid], arr[high]);
                high --;
            }
        }
    }
};
int main(){
    Solution sol;
    int n;
    cout << "Enter size of array: ";
    cin >> n;

   

    vector<int>arr(n);
    cout << "Enter elements of array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
     sol.sortedZero(arr);
for(int nums: arr){
    cout << nums << " ";

}
return 0;
}
