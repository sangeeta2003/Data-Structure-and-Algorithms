#include <bits/stdc++.h>
using namespace std;

bool isPalidrome(int i , string& s){
    if(i >= s.length()/2) return true;

     if (s[i] != s[s.length() - i - 1]) return false;

    return isPalidrome(i+1 , s);
    
}
int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    if (isPalidrome(0, s)) 
        cout << "Palindrome";
    else 
        cout << "Not Palindrome";

    return 0;
}
