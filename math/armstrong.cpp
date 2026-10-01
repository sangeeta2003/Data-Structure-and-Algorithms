#include <bits/stdc++.h>
using namespace std;

int cnt_number_digits(int n){
    int cnt = 0;
    while(n > 0){
        cnt++;
        n /= 10;
    }
    return cnt;
}

bool isArmstrong(int n){
    int original = n;
    int sum = 0;
    int cnt = cnt_number_digits(n);

    while(n > 0){
        int rem = n % 10;
        int power = 1;

        for(int i = 0; i < cnt; i++){
            power *= rem;
        }

        sum += power;
        n /= 10;
    }
    return sum == original;
}

int main(){
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    if(isArmstrong(n))
        cout << "Yes, it is an Armstrong number";
    else
        cout << "Not an Armstrong number";
}
