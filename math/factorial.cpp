#include <bits/stdc++.h>
using namespace std;

long long cntFactorial(long long n){
    if(n == 0) return 1;
    return n * cntFactorial(n - 1);
}

int main(){
    long long n;
    cout << "enter n value : ";
    cin >> n;

    long long result = cntFactorial(n);
    cout << "result is: " << result;
}
