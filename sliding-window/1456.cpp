class Solution {
    bool isVowels(char c){
       
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c== 'u') return true;
        
        return false;
    }
public:
    int maxVowels(string s, int k) {
        int cnt = 0;
        int maxCnt = 0;
        int n = s.size();
        for(int i = 0 ; i < k ;i++){
            if(isVowels(s[i])){
                cnt++;
            }
        }
        maxCnt = cnt;
        for(int right = k ;right < n ;right++){
            if(isVowels(s[right])) cnt++;
            if(isVowels(s[right - k])) cnt--;
            maxCnt = max(cnt, maxCnt);
        }
        return maxCnt;

        
    }
};