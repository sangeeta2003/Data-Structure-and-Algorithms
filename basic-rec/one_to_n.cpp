#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void printNum(int N , int i){
        if (i > N) return ;
        cout << i ;

        printNum(N , i +1);
    }
};

int main(){
    Solution sol;
    int N;
    cout << "Enter value of N :";
    cin >> N;

   sol.printNum(N , 1);
}