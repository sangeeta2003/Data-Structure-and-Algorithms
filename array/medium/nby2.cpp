#include <bits/stdc++.h>
using namespace std;


class Solution{
    public :
    int majorityElement(vector<int>& arr){
        int n = arr.size();
        int cnt = 0;
        int el;
        for(int i = 0 ; i < n ; i++){
            if(cnt == 0){
                el = arr[i];
                cnt++;
            }
           else if(el == arr[i]){
            cnt++;
           }else{
            cnt--;
           }
        }
        int cnt1 = 0;
        for(int i = 0 ; i < n ;i++){
            if(arr[i] == el) cnt1++;
            
        }
        if(cnt1 > n /2 ){
            return el;
        }
        return -1;
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
   int element =   sol.majorityElement(arr);
cout << element;
return 0;
}