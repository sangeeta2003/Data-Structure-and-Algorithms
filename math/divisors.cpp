#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> getDivisrors(int n){
        vector<int> res;

        for(int i = 1; i <= sqrt(n); i++){
            if(n % i == 0){
                res.push_back(i);

               
                if(i != n / i){
                    res.push_back(n / i);
                }
            }
        }

        return res;
    }
};

int main(){
    Solution sol;
    int n;
    cout << "enter the value of n: ";
    cin >> n;

    vector<int> result = sol.getDivisrors(n);

    cout << "Divisors of " << n << ": ";
    for(int val : result){
        cout << val << " ";
    }
}
