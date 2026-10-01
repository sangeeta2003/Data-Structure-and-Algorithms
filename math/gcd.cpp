#include <bits/stdc++.h>
using namespace std;

int gcdCnt(int a , int b){
    int gcd = 0;

    while(a > 0 && b > 0){
        if(a > b) a = a % b;
        else b = b % a;

    }
    if(a == 0) return b;
     return a;

}

int main(){
    int a , b;
    cout << "Enter values of a : ";

    cin >> a;

    cout << "Enter values of b : ";

    cin >> b;

    int gcd = gcdCnt(a , b);

    cout << "gcd of the a and b is: " << gcd;

}