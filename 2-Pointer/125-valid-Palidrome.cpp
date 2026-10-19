class Solution {
    private:
    string build(string s){
        string res;
        for(char c : s){
            if(isalnum(c)){
 res.push_back(tolower(c));
            }
               

            }
        
return res;
    }
public:
    bool isPalindrome(string s) {
        
        string converted = build(s);
        int n = converted.size();
        int i = 0;
        int j= n -1;
        while(i < j){
            if(converted[i] != converted[j]){
                return false;
            }
            i++;
            j--;
        }
        
return true;
    }
};