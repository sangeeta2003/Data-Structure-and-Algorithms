#include <bits/stdc++.h>
using namespace std;

int RevNumCnt(int n){
    int revNum = 0;
    while(n > 0){
        int rem = n % 10;
        revNum = revNum * 10 + rem;
        n /= 10;
    }
    return revNum;
}

int main(){
    int n;
    cout <<  "Enter value of n :";

    cin >> n;

    int revNum = RevNumCnt(n);

    cout << "Reverse number is :" << revNum;



}