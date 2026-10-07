class Solution {
public:
    vector<string> res;
    unordered_set<string> st;

    void solve(string s, int index, int left, int right, int balance) {

        if (index == s.size()) {
            if (balance == 0) {
                st.insert(s);
            }
            return;
        }

        if (s[index] == '(') {
            // Remove '('
            solve(s.substr(0, index) + s.substr(index + 1),
                  index, left - 1, right, balance);

            // Keep '('
            solve(s, index + 1, left, right, balance + 1);
        }
        else if (s[index] == ')') {

            // Remove ')'
            solve(s.substr(0, index) + s.substr(index + 1),
                  index, left, right - 1, balance);

            // Keep ')' only if valid
            if (balance > 0) {
                solve(s, index + 1, left, right, balance - 1);
            }
        }
        else {
            solve(s, index + 1, left, right, balance);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int balance = 0;
        int leftRemove = 0;
        int rightRemove = 0;

        for (char c : s) {
            if (c == '(') {
                balance++;
            }
            else if (c == ')') {
                if (balance > 0)
                    balance--;
                else
                    rightRemove++;
            }
        }

        leftRemove = balance;

        function<void(int, int, int, string)> dfs =
            [&](int index, int left, int right, string current) {

            if (index == s.size()) {
                if (left == 0 && right == 0) {
                    int bal = 0;

                    for (char c : current) {
                        if (c == '(') bal++;
                        else if (c == ')') {
                            if (bal == 0) return;
                            bal--;
                        }
                    }

                    if (bal == 0)
                        st.insert(current);
                }
                return;
            }

            char c = s[index];

            if (c == '(' && left > 0) {
                dfs(index + 1, left - 1, right, current);
            }

            if (c == ')' && right > 0) {
                dfs(index + 1, left, right - 1, current);
            }

            dfs(index + 1, left, right, current + c);
        };

        dfs(0, leftRemove, rightRemove, "");

        for (auto &x : st)
            res.push_back(x);

        return res;
    }
};