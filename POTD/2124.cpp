class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        for(int i = 0 ; i < n ;i++){
            if(s[i] == 'b' && s[i+1] == 'a'){
                return false;
            }
        }
        return true;
    }
};