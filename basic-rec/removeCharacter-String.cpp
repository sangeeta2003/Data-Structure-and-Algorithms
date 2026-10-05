class Solution {
private:
    void fun(string &s, char c, int i, string &ans) {

        if (i == s.size())
            return;

        if (s[i] != c)
            ans.push_back(s[i]);

        fun(s, c, i + 1, ans);
    }

public:
    void removeCharacter(string &s, char c) {
        string ans;
        fun(s, c, 0, ans);
        s = ans;
    }
};