class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        int n = s.size();
        int m = p.size();

        vector<int> ans;

        if (m > n) return ans;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        // Store frequency of p
        for (char c : p) {
            freq1[c - 'a']++;
        }

        // First window of size m
        for (int i = 0; i < m; i++) {
            freq2[s[i] - 'a']++;
        }

        if (freq1 == freq2) {
            ans.push_back(0);
        }

        // Slide the window
        for (int right = m; right < n; right++) {

            // Add incoming character
            freq2[s[right] - 'a']++;

            // Remove outgoing character
            freq2[s[right - m] - 'a']--;

            if (freq1 == freq2) {
                ans.push_back(right - m + 1);
            }
        }

        return ans;
    }
};