class Solution {
private:
    void fun(vector<string>& ans, string& s, int open, int close, int n) {

        // Valid combination completed
        if(close == s.size() && open == s.size()) {
            ans.push_back(s);
            return;
        }

        // Add '(' if we still have opening brackets
        if(open < n) {
            s.push_back('(');
            fun(ans, s, open + 1, close, n);
            s.pop_back();
        }

        // Add ')' only when there is an unmatched '('
        if(close < open) {
            s.push_back(')');
            fun(ans, s, open, close + 1, n);
            s.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {

        vector<string> ans;
        string s;

        fun(ans, s, 0, 0, n);

        return ans;
    }
};