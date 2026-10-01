#include <bits/stdc++.h>
using namespace std;


class Solution{
    public :
    int singleElem(vector<int>& arr){
        int n = arr.size();
        int xor1 = 0;
        for(int i = 0 ; i < n ;i++){
            xor1 = xor1 ^ arr[i];
        }
        return xor1;

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
    int single = sol.singleElem(arr);
    cout << single;
    return 0;
}
