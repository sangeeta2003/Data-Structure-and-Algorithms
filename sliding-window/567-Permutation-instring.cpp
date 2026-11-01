class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
         if(n > m) return false;
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        for(char c : s1){
            freq1[c- 'a']++;
        }
        for(int i = 0; i < n ;i++){
            freq2[s2[i] - 'a']++;
        }
        if(freq1 == freq2 ) return true;
        for(int right = n ; right < m ;right++){
            freq2[s2[right] -'a']++;
            freq2[s2[right - n] - 'a']--;
             if (freq1 == freq2) return true;
        }
        
        return false;
    }
};