#include <bits/stdc++.h>
using namespace std;

class Solution{
    public :
    void printName(string name , int N , int cnt){
        if(cnt == N) return;
        cout << name << '\n';
        printName(name , N, cnt + 1);
    }


};
int main(){
    Solution sol;
    string name;
    cout << "Enter the name :";
    cin >> name;
    int N;
    cout << "enter value of N :";
    cin >> N;

    sol.printName(name, N , 0);
    return 0;

}
