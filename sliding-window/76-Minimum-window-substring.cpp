class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> freq(256, 0);

        int n = s.size();
        int m = t.size();

        int l = 0, r = 0;
        int startIndx = -1;
        int minIdx = INT_MAX;
        int cnt = 0;

        for(int i = 0; i < m; i++) {
            freq[t[i]]++;
        }

        while(r < n) {

            if(freq[s[r]] > 0) {
                cnt++;
            }

            freq[s[r]]--;

            while(cnt == m) {

                int Window = r - l + 1;

                if(Window < minIdx) {
                    minIdx = Window;
                    startIndx = l;
                }

                freq[s[l]]++;

                if(freq[s[l]] > 0) {
                    cnt--;
                }

                l++;
            }

            r++;
        }

        return startIndx == -1 ? "" :
               s.substr(startIndx, minIdx);
    }
};