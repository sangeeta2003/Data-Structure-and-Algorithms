class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());

        if (st.find(endWord) == st.end()) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        st.erase(beginWord);

        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            string s = p.first;
            int steps = p.second;

            if (s == endWord) return steps;

            for (int i = 0; i < s.size(); i++) {
                char original = s[i];

                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == original) continue;

                    s[i] = c;

                    if (st.find(s) != st.end()) {
                        q.push({s, steps + 1});
                        st.erase(s);
                    }
                }

                s[i] = original;
            }
        }

        return 0;
    }
};