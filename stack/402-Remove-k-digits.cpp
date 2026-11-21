class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for(char c : num) {
            while(!st.empty() && k > 0 && st.top() > c) {
                st.pop();
                k--;
            }

            st.push(c);
        }

        // If removals are still remaining,
        // remove digits from the end
        while(k > 0) {
            st.pop();
            k--;
        }

        string ans = "";

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        // Remove leading zeros
        int i = 0;
        while(i < ans.size() && ans[i] == '0') {
            i++;
        }

        ans = ans.substr(i);

        if(ans.empty()) return "0";

        return ans;
    }
};