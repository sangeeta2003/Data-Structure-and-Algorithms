class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> freq(26, 0);

        // Count frequency of each task
        for (char c : tasks) {
            freq[c - 'A']++;
        }

        // Find maximum frequency
        int maxFreq = 0;
        for (int f : freq) {
            maxFreq = max(maxFreq, f);
        }

        // Count tasks having maximum frequency
        int maxFreqTasks = 0;
        for (int f : freq) {
            if (f == maxFreq) {
                maxFreqTasks++;
            }
        }

        // Calculate required intervals
        int ans = (maxFreq - 1) * (n + 1) + maxFreqTasks;

        // We cannot have fewer intervals than total tasks
        return max(ans, (int)tasks.size());
    }
};