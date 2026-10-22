class Solution {
  public:
    int minimumSum(string &s) {
        int n = s.size();

        // Step 1: Make the string a palindrome
        for (int i = 0; i < n / 2; i++) {
            int j = n - 1 - i;

            // Both characters are fixed but different
            if (s[i] != '?' && s[j] != '?' && s[i] != s[j]) {
                return -1;
            }

            // Copy the known character to the '?'
            if (s[i] == '?') {
                s[i] = s[j];
            }

            if (s[j] == '?') {
                s[j] = s[i];
            }
        }

        // Step 2: Find the minimum cost
        int ans = 0;
        char last = '?';

        for (int i = 0; i <= n / 2; i++) {
            if (s[i] == '?') {
                continue;
            }

            if (last != '?') {
                ans += abs(s[i] - last);
            }

            last = s[i];
        }

        // Each difference occurs twice in a palindrome
        return ans * 2;
    }
};