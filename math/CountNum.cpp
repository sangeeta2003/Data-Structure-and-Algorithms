#include<bits/stdc++.h>
using namespace std;

int CountNumber(int n){
    int cnt = 0;
    while(n > 0){
        cnt++;
        n /= 10 ;
    }
    return cnt;
}

int main(){
    int n;
    cin >> n;
    int totalCnt = CountNumber(n);


   cout << "Number of count is : " << totalCnt;



}


