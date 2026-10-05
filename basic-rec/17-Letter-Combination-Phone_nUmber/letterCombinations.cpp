class Solution {
     unordered_map<char, string> f{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void fun(string &digits,int idx,int n , string &diary,vector<string> &res){
        if(idx == n) res.push_back(diary);
        string choices = f[digits[idx]];
        for(int j = 0 ; j < choices.size();j++){
            diary.push_back(choices[j]);
            fun(digits,idx + 1 , n , diary,res);
            diary.pop_back();

        }
        
    }

public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string>res;
        string diary = "";
        fun(digits,0,digits.size(),diary,res);
        return res;
        
    }
};