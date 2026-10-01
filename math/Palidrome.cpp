#include <bits/stdc++.h>
using namespace std;

bool isPalidrome(int n){
    int revNum = 0;
    while(n > 0){
        int rem = n % 10;
        revNum = revNum * 10 + rem;
        n /= 10;
    }
  return revNum == n;
}

int main(){
    int n;
    cout <<  "Enter value of n :";

    cin >> n;

   if(isPalidrome(n))
   cout << "It is a palindrome";
    else
        cout << "It is not a palindrome";

    // cout << "Reverse number is :" << revNum;

return 0;

}