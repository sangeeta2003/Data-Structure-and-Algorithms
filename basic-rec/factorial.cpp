#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int facOfN(int N ){
        int sum = 0;
       
if(N == 1) return 1;
        

return N * facOfN(N  - 1);
        }

    
};

int main(){
    Solution sol;
    int N;
    cout << "enter value of N :";
    cin >> N;
   cout << sol.facOfN(N);
    return 0;
}