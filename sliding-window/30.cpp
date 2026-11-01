class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        int n = s.size();
        int wordLen = words[0].size();
        int wordCount = words.size();

        int totalLen = wordLen * wordCount;

        if (n < totalLen) return ans;

        unordered_map<string, int> freq;

        // Store required word frequencies
        for (string word : words) {
            freq[word]++;
        }

        // Try every possible starting offset
        for (int i = 0; i < wordLen; i++) {

            unordered_map<string, int> seen;

            int left = i;
            int count = 0;

            for (int right = i; right + wordLen <= n; right += wordLen) {

                string word = s.substr(right, wordLen);

                // If word is not present in words
                if (freq.find(word) == freq.end()) {
                    seen.clear();
                    count = 0;
                    left = right + wordLen;
                    continue;
                }

                seen[word]++;
                count++;

                // Remove extra occurrences
                while (seen[word] > freq[word]) {

                    string leftWord = s.substr(left, wordLen);

                    seen[leftWord]--;
                    count--;
                    left += wordLen;
                }

                // All words matched
                if (count == wordCount) {

                    ans.push_back(left);

                    // Move left by one word to find overlapping matches
                    string leftWord = s.substr(left, wordLen);

                    seen[leftWord]--;
                    count--;
                    left += wordLen;
                }
            }
        }

        return ans;
    }
};