class Solution {
      bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' ||
               c == 'o' || c == 'u' || c == 'A' ||
               c == 'E' || c == 'I' || c == 'O' ||
               c == 'U';
    }
public:
    string reverseVowels(string s) {
        int n = s.size();
        int j = n-1;
      int i = 0;
      while(i  < j){
        while(i < j && !isVowel(s[i])){
            i++;
        }
         while(i < j && !isVowel(s[j])){
            j--;
        }
        swap(s[i],s[j]);
        i++;
        j--;
      }
      return s;
    }
};