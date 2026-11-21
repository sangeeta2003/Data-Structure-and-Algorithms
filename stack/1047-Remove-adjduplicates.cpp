class Solution {
public:
    string removeDuplicates(string s) {
        stack<int>st;
        string res = "";
        int n = s.size();
        for(int i = 0 ; i < n ;i++){
if(!st.empty() && s[i] == st.top()){
    st.pop();
}else{
    st.push(s[i]);
}
        }
        
        while(!st.empty()){
           res += st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};