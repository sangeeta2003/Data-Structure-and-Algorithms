class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        bool sorted = true;
        for (int i = 1; i < n; ++i) {
            if (s[i] < s[i - 1]) {
                sorted = false;
                break;
            }
        }
        if (sorted) return 0;
        if (n == 2) return -1;
        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());
        if (s[0] == mn || s[n - 1] == mx) return 1;
        for (int i = 1; i < n - 1; ++i) {
            if (s[i] == mn || s[i] == mx) return 2;
        }
        return 3;
    }
};

// Already sorted → return 0.



// Length is 2 and unsorted → return -1 because you cannot sort the entire string.



// First character = minimum OR last character = maximum → return 1.



// Minimum or maximum exists in the middle → return 2.



// Otherwise → return 3 (maximum is first and minimum is last).