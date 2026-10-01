#include <bits/stdc++.h>
using namespace std;


class Solution{
    public :
   int consecutiveOne(vector<int>& arr){
    int n = arr.size();
    if(n == 0) return 0;
    int longest = 1;

unordered_set<int>st;
for(int i =0 ; i < n ;i++){
    st.insert(arr[i]);
}
for(auto it : st){
    if(st.find(it - 1) == st.end()){
        int cnt = 1;
        int x = it;
        while(st.find(x + 1) != st.end()){
            x = x + 1;
            cnt = cnt + 1;

        }
        longest = max(longest,cnt);
    }
}
return longest;


   }};

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

  int ans =  sol.consecutiveOne(arr);
   cout << ans;
    return 0;


}
