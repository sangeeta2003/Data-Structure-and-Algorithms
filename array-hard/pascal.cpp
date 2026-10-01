#include <bits/stdc++.h>
using namespace std;


class Solution{
    public :
    int pascal(int r , int c){
        int result = 1;
        int n = r -1 ; int k = c- 1;
        for(int i =0 ; i < k ; i++){
            result = result * (n -i) / (i + 1);

        }
        return result;


    }
};
int main(){
    Solution sol;
int r;
 cout << "Enter value of r";
    cin >> r;
    int c;
     cout << "Enter value of c";
    cin >> c;
    long long result = sol.pascal(r , c);
   
    cout << result;
    return 0;
}