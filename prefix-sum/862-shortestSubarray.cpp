
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        deque<int> dq;
        int ans = n + 1;

        for (int i = 0; i <= n; i++) {

            // Condition 1: Find valid subarrays
            while (!dq.empty() &&
                   prefix[i] - prefix[dq.front()] >= k) {

                ans = min(ans, i - dq.front());
                dq.pop_front();
            }

            // Condition 2: Maintain increasing prefix sums
            while (!dq.empty() &&
                   prefix[dq.back()] >= prefix[i]) {

                dq.pop_back();
            }

            dq.push_back(i);
        }

        return ans == n + 1 ? -1 : ans;
    }
};
