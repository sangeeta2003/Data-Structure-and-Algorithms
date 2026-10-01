#include <bits/stdc++.h>
using namespace std;


class Solution{
    public :
   vector<int> nextPermutation(vector<int>& arr){
int n = arr.size();
vector<int>permutations;
permutations.push_back(arr[n-1]);
int leader = arr[n-1];
for(int i = n -2 ; i >= 0 ; i--){
    if(arr[i] > leader){
permutations.push_back(arr[i]);
leader = arr[i];
    }
    
}
reverse(permutations.begin(), permutations.end());
return permutations;
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

   vector<int>ans =  sol.nextPermutation(arr);
    for(int nums : ans){
        cout << nums;
    }
    return 0;


}